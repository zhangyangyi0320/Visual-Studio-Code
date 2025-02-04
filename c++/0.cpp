#include <wx/wx.h>

class MyFrame: public wxFrame
{
public:
    MyFrame(const wxString& title)
        : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(300, 200))
    {
        wxPanel *panel = new wxPanel(this, wxID_ANY);
        wxStaticText *helloLabel = new wxStaticText(panel, wxID_ANY, "HELLOWORLD", wxPoint(100, 50));
    }
};

class MyApp: public wxApp
{
public:
    virtual bool OnInit()
    {
        MyFrame *frame = new MyFrame("Hello wxWidgets");
        frame->Show(true);
        return true;
    }
};

wxIMPLEMENT_APP(MyApp);
