#include "resource.h"
#include <AsyncMFCDialog/AsyncGenericDialog.hpp>
#include <afxwin.h> // Ensure MFC is included
#include <iostream>
#include <memory>

// A simple mock MFC Dialog for testing
class MyDialog : public CDialog {
public:
  MyDialog() : CDialog(IDD_DIALOG1) {}
  void DoSomething() {
    // Simulating some action
    std::cout << "Dialog action performed!" << std::endl;
  }
};

int main() {
  // Create a dialog
  auto dialog = std::make_shared<MyDialog>();

  // Define a task to be executed asynchronously
  auto task = [](MyDialog *dlg) -> int {
    dlg->DoSomething();
    return 42; // Result of the async task
  };

  // Instantiate and use the async dialog class
  TAsyncGenericDialog<MyDialog, int> asyncDialog(dialog, task);
  int result = asyncDialog.Await();

  std::cout << "Result: " << result << std::endl;
  return 0;
}