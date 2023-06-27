#ifndef APPS_UART_MONITOR_CONTROLLER_H
#define APPS_UART_MONITOR_CONTROLLER_H

#include <escher/app.h>
#include <escher/buffer_text_view.h>
#include <escher/text_field.h>
#include <escher/text_input.h>
#include <escher/toolbox.h>
#include <escher/text_field_delegate.h>

namespace Uart {

class MonitorController : public Escher::ViewController, public Escher::Timer, public Escher::TextFieldDelegate {
public:
  MonitorController (Responder * parentResponder);
  Escher::View * view() override;
  bool fire() override;
  void didBecomeFirstResponder() override;
  Escher::Toolbox * toolboxForTextInput(Escher::TextInput * textInput);
  bool textFieldShouldFinishEditing(Escher::TextField * textInput, Ion::Events::Event event);
  bool textFieldDidFinishEditing(Escher::TextField * textField, const char * text, Ion::Events::Event event);
  bool textFieldDidReceiveEvent(Escher::TextField*, Ion::Events::Event);
private:
  class MonitorView : public Escher::View {
  public:
    MonitorView(char * buffer, size_t bufferSize, TextFieldDelegate * delegate);
    ~MonitorView();
    void drawRect(KDContext * ctx, KDRect rect) const override;
    int numberOfSubviews() const override;
    View * subviewAtIndex(int index) override;

    void putChar(const char c);
    void clearInput();

    Escher::TextField * textField();
  private:
    constexpr static int k_numberOfLines = 8;
    constexpr static int k_lengthLimit = 30;
    void layoutSubviews();
    void trimLine();
    char * m_buffer;
    char * m_draftBuffer;
    int m_lines;
    int m_length;
    Escher::BufferTextView m_statusView;
    Escher::BufferTextView m_textView;
    Escher::TextField m_textField;
  };
  char m_buffer[100];
  MonitorView m_monitorView;
};

}

#endif
