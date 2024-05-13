#pragma once
#include "EventRegisterBase.h"
#include "Core/IEventRegister.h"
#include "ll/api/event/Listener.h"

using ll::event::ListenerPtr;

class MoneyEventRegister : public EventRegisterBase {

private:
    ListenerPtr playerJoinEventListener;
    ListenerPtr playerUseItemEventListener;

public:
    MoneyEventRegister() { }

    void EventRegister() override;
    void RemoveEventListener() override;

};
