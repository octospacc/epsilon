#ifndef APPS_UART_CONTROLLER_H
#define APPS_UART_CONTROLLER_H

#include "monitor_controller.h"
#include <escher/app.h>
#include <escher/message_table_cell_with_buffer.h>
#include <escher/message_table_cell_with_switch.h>
#include <escher/selectable_table_view.h>
#include <escher/metric.h>
#include <escher/responder.h>

namespace Uart {

class MainController : public Escher::ViewController, public Escher::ListViewDataSource, public Escher::SelectableTableViewDataSource {
public:
  MainController (Responder * parentResponder, bool & usart6);
  Escher::View * view() override;

  bool handleEvent(Ion::Events::Event event) override;
  void didBecomeFirstResponder() override;

  int numberOfRows();
  KDCoordinate rowHeight(int j);

  KDCoordinate cumulatedHeightFromIndex(int j);
  int indexFromCumulatedHeight(KDCoordinate offsetY);

  Escher::HighlightCell * reusableCell(int index, int type) override;
  int reusableCellCount(int type) override;
  //int typeAtLocation(int i, int j);
  void willDisplayCellForIndex(Escher::HighlightCell * cell, int index) override;
  Escher::Timer * getRxTimer();
private:
  constexpr static int k_numberOfCellsWithBuffer = 4;
  Escher::MessageTableCellWithSwitch m_cellWithSwitch;
  Escher::MessageTableCellWithBuffer m_cellsWithBuffer[k_numberOfCellsWithBuffer];
  Escher::MessageTableCellWithChevron m_cellWithChevron;
  Escher::SelectableTableView m_selectableTableView;
  MonitorController * m_monitorController;
  bool & m_usart6;
};

}

#endif
