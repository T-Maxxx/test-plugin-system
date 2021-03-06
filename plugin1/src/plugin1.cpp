#include "plugin1.hpp"

#include "interface/bar_000.hpp"
#include "plugin_api.hpp"
#include "interface/foo_000.hpp"


using namespace std;
IMPL_PLUGIN(CPlugin1);

const char* CPlugin1::GetName() const
{
    return "Test plugin 1 (deprecated)";
}


const char* CPlugin1::GetDescription() const
{
    return "First created plugin";
}


const char* CPlugin1::GetShortDescription() const
{
    return "This plugin uses \"deprecated\" API to do some cool stuff";
}


void CPlugin1::GetVersion(uint32_t& Major_, uint32_t& Minor_) const
{
    Major_ = 1;
    Minor_ = 0;
}


void CPlugin1::OnPluginLoaded()
{
    auto pBar = GetInterface<plugin_api::IBar000>();
    if (!pBar)
        return;

    pBar->BarA();
}


void CPlugin1::OnPluginUnloaded()
{
    auto pFoo = GetInterface<plugin_api::IFoo000>();
    if (!pFoo)
        return;

    pFoo->FooA();
    pFoo->FooB(10);
}


bool CPlugin1::EventA(int A1_)
{
    return A1_ < 0;
}
