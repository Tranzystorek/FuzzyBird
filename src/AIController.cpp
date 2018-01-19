#include "AIController.hpp"

#include <iostream>

#include "Constants.hpp"

#include "EngineProperties.hpp"
#include "EngineFactory.hpp"

using namespace flogic;

AIController::AIController()
    : altmin_(0.1 * Constants::PIPE_SPACING)
{
    //compute parameters
    qreal xhor = altmin_ * (Constants::PIPE_SPEED / Constants::FALLING_SPEED);

    EngineProperties props;

    //altitude variable
    VariableProperties alt;

    alt.name = "Altitude";
    alt.range = Range(-1., 1.);

    TermProperties low;
    low.name = "Low";
    low.type = TermProperties::BINARY;
    low.params = { 1., -1., 1., 0. };

    TermProperties ok;
    ok.name = "Ok";
    ok.type = TermProperties::BINARY;
    ok.params = { 1., 1., -1., 0. };

    alt.terms = { low, ok };

    //xpos variable
    VariableProperties xpos;

    xpos.name = "XPos";
    xpos.range = Range(-1., 1.);

    TermProperties unsafe;
    unsafe.name = "Unsafe";
    unsafe.type = TermProperties::BINARY;
    unsafe.params = { 1., 1., -1., xhor };

    TermProperties safe;
    safe.name = "Safe";
    safe.type = TermProperties::RECTANGLE;
    safe.params = { 1., 0., xhor };

    xpos.terms = { unsafe, safe };

    //add variables to engine
    props.invars = { alt, xpos };

    //output variable
    VariableProperties& out = props.outvar;

    out.name = "Movement";
    out.range = Range(-1., 1.);

    TermProperties flap;
    flap.name = "Flap";
    flap.type = TermProperties::BINARY;
    flap.params = { 1., 1., 1., 0. };

    TermProperties fall;
    fall.name = "Fall";
    fall.type = TermProperties::BINARY;
    fall.params = { 1., -1., 1., 0. };

    out.terms = { flap, fall };

    //rules
    RuleProperties first;
    RuleProperties::ConditionBlock a;
    a.vname = "Altitude";
    a.tname = "Low";

    RuleProperties::ConditionBlock b;
    b.vname = "XPos";
    b.tname = "Unsafe";

    first.conditions = { a, b };

    first.conclusion.vname = "Movement";
    first.conclusion.tname = "Flap";

    RuleProperties second;
    RuleProperties::ConditionBlock c;
    c.vname = "Altitude";
    c.tname = "Low";

    RuleProperties::ConditionBlock d;
    d.vname = "XPos";
    d.tname = "Safe";

    second.conditions = { c, d };

    second.conclusion.vname = "Movement";
    second.conclusion.tname = "Fall";

    RuleProperties third;
    RuleProperties::ConditionBlock e;
    e.vname = "Altitude";
    e.tname = "Ok";

    third.conditions = { e };

    third.conclusion.vname = "Movement";
    third.conclusion.tname = "Fall";

    props.rules = { first, second, third };

    //implication
    props.implication.function = TNormProperties::ALGEBRAIC_PRODUCT;

    //aggregation
    props.aggregation.function = SNormProperties::BOUNDED_SUM;

    //defuzzifier
    props.defuzzifier.type = DefuzzifierProperties::CENTROID;
    props.defuzzifier.resolution = 100;

    //generate engine
    eng_.reset(EngineFactory::createEngine(props));
}

void AIController::receiveData(qreal birdalt, qreal pipealt, qreal birdhor, qreal pipehor)
{
    qreal dalt = pipealt - birdalt - altmin_;
    qreal dhor = pipehor - birdhor;

    eng_->setInput("Altitude", dalt);
    eng_->setInput("XPos", dhor);
    eng_->process();

    flogic::Scalar out = eng_->getOutput();

    if(out > 0.)
        emit flap();
}
