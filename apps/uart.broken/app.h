#ifndef UART_APP_H
#define UART_APP_H

#include <apps/shared/shared_app.h>
#include <escher/app.h>
#include "main_controller.h"

namespace Uart {

class App : public Shared::SharedApp {
public:
  class Descriptor : public Escher::App::Descriptor {
  public:
    I18n::Message name();
    I18n::Message upperName();
    const Escher::Image * icon();
  };
  class Snapshot : public Shared::SharedApp::Snapshot {
  public:
    Snapshot();
    App * unpack(Escher::Container * container) override;
    void reset() override;
    const Descriptor * descriptor() const override;
    bool & usart6();
  private:
    bool m_usart6;
  };
  int numberOfTimers() override;
  Escher::Timer * timerAtIndex(int i) override;
private:
  App(Snapshot * snapshot);
  MainController * m_mainController;
};

}

#endif
