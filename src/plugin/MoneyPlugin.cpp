#include "plugin/MoneyPlugin.h"

#include <memory>

#include "Command/MoneyCommandRegister.h"
#include "Event/MoneyEventRegister.h"
#include "ll/api/plugin/NativePlugin.h"
#include "ll/api/plugin/RegisterHelper.h"
#include "plugin/Log/Log.h"

namespace MoneyPlugin {

static std::unique_ptr<MoneyPlugin> instance;

MoneyPlugin& MoneyPlugin::getInstance() { return *instance; }

bool MoneyPlugin::load() {
    Log::Init(&getSelf().getLogger());
    Log::Info("插件加载中...Loading...");
    
    return true;
}

bool MoneyPlugin::enable() {
    command_register = new MoneyCommandRegister();
    event_register = new MoneyEventRegister();

    command_register->CommandRegister();
    event_register->EventRegister();

    
    return true;
}

bool MoneyPlugin::disable() {
    Log::Info("插件关闭中...Disabling...");
    
    event_register->RemoveEventListener();
    return true;
}

} 

LL_REGISTER_PLUGIN(MoneyPlugin::MoneyPlugin, MoneyPlugin::instance);
