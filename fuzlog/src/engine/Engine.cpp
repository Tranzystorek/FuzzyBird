#include "Engine.hpp"

#include <algorithm>

using namespace flogic;

Engine::Engine()
{
    //TODO everything?
}

void Engine::process()
{
    activate();
    calculate();
}

void Engine::activate()
{
    std::vector<Scalar> activations(ands_.size());

    std::transform(ands_.begin(), ands_.end(),
                   activations.begin(),
                   [this](const AndExpr& expr){return expr.evaluate(inputs_, inputnames_);});

    ruleblock_.setActivations(activations);
}

void Engine::calculate()
{
    Scalar output = defuzz_->defuzzify(ruleblock_.getAggregator(), output_.getRange());

    output_.setOutput(output);
}
