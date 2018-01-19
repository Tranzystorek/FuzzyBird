#include "EngineFactory.hpp"

using namespace flogic;

#include "utility.h"

#include <algorithm>
#include <utility>

#include "Binary.hpp"
#include "Ramp.hpp"
#include "Rectangle.hpp"
#include "Trapezoid.hpp"
#include "Triangle.hpp"

#include "AlgebraicProduct.hpp"
#include "Minimum.hpp"

#include "BoundedSum.hpp"
#include "Maximum.hpp"

#include "Bisector.hpp"
#include "Centroid.hpp"

EngineFactory::EngineFactory()
{

}

Engine* EngineFactory::createEngine(const EngineProperties& props)
{
    Engine* constructed = new Engine();

    //TODO construction

    //generate input variables
    int varindex = 0;
    for(auto& var : props.invars)
    {
        std::vector<TermObject> terms(var.terms.size());

        auto it = terms.begin();
        for(auto& term : var.terms)
        {
            it->reset(TermFactory::createTerm(term));
            ++it;
        }

        constructed->inputs_.emplace_back(var.name, var.range,
                                         std::move(terms));

        constructed->inputnames_.emplace(var.name, varindex++);
    }

    //generate output variable
    const VariableProperties& outvar = props.outvar;

    std::vector<TermObject> terms(outvar.terms.size());

    auto it = terms.begin();
    for(auto& term : outvar.terms)
    {
        it->reset(TermFactory::createTerm(term));
        ++it;
    }

    constructed->output_ = OutputVar(outvar.name, outvar.range,
                                    std::move(terms));

    //generate rules (andexprs + implicators in aggregator)
    std::vector<Implicator> impls;

    int condindex = 0;
    for(auto& rule : props.rules)
    {
        std::vector<TermBinding> binds(rule.conditions.size());

        auto it = binds.begin();
        for(auto& cond : rule.conditions)
        {
            it->invar = cond.vname;
            it->term = cond.tname;

            ++it;
        }

        constructed->ands_.emplace_back(binds, new Minimum());

        impls.emplace_back(TNormFactory::createTNorm(props.implication),
                           constructed->output_.getTerm(rule.conclusion.tname).get());
    }

    constructed->ruleblock_ = RuleBlock(SNormFactory::createSNorm(props.aggregation),
                                       std::move(impls));

    //generate defuzzifier
    constructed->defuzz_.reset(DefuzzifierFactory::createDefuzzifier(props.defuzzifier));

    return constructed;
}

TermFactory::TermFactory()
{

}

Term* TermFactory::createTerm(const TermProperties& props)
{
    const std::vector<Scalar>& params = props.params;

    if(props.type == TermProperties::BINARY)
    {
        Binary::Direction dir;
        Scalar dirsc = params[1];

        if(Op::isLt(dirsc, 0.))
            dir = Binary::LEFT;
        else if(Op::isGt(dirsc, 0.))
            dir = Binary::RIGHT;

        Binary::Inclusivity incl;
        Scalar inclsc = params[2];

        if(Op::isLt(inclsc, 0.))
            incl = Binary::INCLUSIVE;
        else if(Op::isGt(inclsc, 0.))
            incl = Binary::EXCLUSIVE;

        return new Binary(props.name, params[3], params[0], dir, incl);
    }

    else if(props.type == TermProperties::RAMP)
    {
        Ramp::Direction dir;
        Scalar dirsc = params[1];

        if(Op::isLt(dirsc, 0.))
            dir = Ramp::LEFT;
        else if(Op::isGt(dirsc, 0.))
            dir = Ramp::RIGHT;

        return new Ramp(props.name, params[2], params[3], params[0], dir);
    }

    else if(props.type == TermProperties::RECTANGLE)
    {
        return new Rectangle(props.name, params[1], params[2], params[0]);
    }

    else if(props.type == TermProperties::TRAPEZOID)
    {
        return new Trapezoid(props.name, params[1], params[2], params[3], params[4], params[0]);
    }

    else if(props.type == TermProperties::TRIANGLE)
    {
        return new Triangle(props.name, params[1], params[2], params[3], params[0]);
    }
}

DefuzzifierFactory::DefuzzifierFactory()
{

}

Defuzzifier* DefuzzifierFactory::createDefuzzifier(const DefuzzifierProperties& props)
{
    if(props.type == DefuzzifierProperties::BISECTOR)
    {
        return new Bisector(props.resolution);
    }

    else if(props.type == DefuzzifierProperties::CENTROID)
    {
        return new Centroid(props.resolution);
    }
}

TNormFactory::TNormFactory()
{

}

TNorm* TNormFactory::createTNorm(const TNormProperties& props)
{
    if(props.function == TNormProperties::ALGEBRAIC_PRODUCT)
    {
        return new AlgebraicProduct;
    }

    else if(props.function == TNormProperties::MINIMUM)
    {
        return new Minimum();
    }
}

SNormFactory::SNormFactory()
{

}

SNorm* SNormFactory::createSNorm(const SNormProperties& props)
{
    if(props.function == SNormProperties::BOUNDED_SUM)
    {
        return new BoundedSum();
    }

    else if(props.function == SNormProperties::MAXIMUM)
    {
        return new Maximum();
    }
}
