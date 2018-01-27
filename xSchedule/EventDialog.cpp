#include "EventDialog.h"
#include "events/EventBase.h"
#include "EventE131Panel.h"
#include "EventDataPanel.h"
#include "EventSerialPanel.h"
#include "EventARTNetPanel.h"
#include "EventOSCPanel.h"
#include "EventFPPPanel.h"
#include "xScheduleMain.h"
#include "ScheduleManager.h"
#include "CommandManager.h"
#include "events/EventARTNet.h"
#include "events/EventE131.h"
#include "events/EventData.h"
#include "events/EventOSC.h"
#include "events/EventFPP.h"
#include "events/EventSerial.h"

//(*InternalHeaders(EventDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(EventDialog)
const long EventDialog::ID_CHOICEBOOK1 = wxNewId();
const long EventDialog::ID_BUTTON1 = wxNewId();
const long EventDialog::ID_BUTTON2 = wxNewId();
const long EventDialog::ID_PANEL3 = wxNewId();
const long EventDialog::ID_STATICTEXT5 = wxNewId();
const long EventDialog::ID_TEXTCTRL4 = wxNewId();
const long EventDialog::ID_STATICTEXT1 = wxNewId();
const long EventDialog::ID_CHOICE1 = wxNewId();
const long EventDialog::ID_STATICTEXT4 = wxNewId();
const long EventDialog::ID_TEXTCTRL1 = wxNewId();
const long EventDialog::ID_STATICTEXT3 = wxNewId();
const long EventDialog::ID_TEXTCTRL2 = wxNewId();
const long EventDialog::ID_STATICTEXT2 = wxNewId();
const long EventDialog::ID_TEXTCTRL3 = wxNewId();
const long EventDialog::ID_PANEL2 = wxNewId();
const long EventDialog::ID_SPLITTERWINDOW1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(EventDialog,wxDialog)
	//(*EventTable(EventDialog)
	//*)
END_EVENT_TABLE()

EventDialog::EventDialog(wxWindow* parent, EventBase* eventBase, wxWindowID id,const wxPoint& pos,const wxSize& size)
{
    _eventBase = eventBase;

	//(*Initialize(EventDialog)
	wxFlexGridSizer* FlexGridSizer4;
	wxFlexGridSizer* FlexGridSizer3;
	wxFlexGridSizer* FlexGridSizer2;
	wxFlexGridSizer* FlexGridSizer1;

	Create(parent, id, _("Event"), wxDefaultPosition, wxDefaultSize, wxCAPTION|wxRESIZE_BORDER|wxMAXIMIZE_BOX, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	FlexGridSizer1 = new wxFlexGridSizer(0, 1, 0, 0);
	FlexGridSizer1->AddGrowableCol(0);
	FlexGridSizer1->AddGrowableRow(0);
	SplitterWindow1 = new wxSplitterWindow(this, ID_SPLITTERWINDOW1, wxDefaultPosition, wxSize(20,20), wxSP_3D, _T("ID_SPLITTERWINDOW1"));
	SplitterWindow1->SetMinSize(wxSize(10,10));
	SplitterWindow1->SetMinimumPaneSize(10);
	SplitterWindow1->SetSashGravity(0.5);
	Panel3 = new wxPanel(SplitterWindow1, ID_PANEL3, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL3"));
	FlexGridSizer3 = new wxFlexGridSizer(0, 1, 0, 0);
	FlexGridSizer3->AddGrowableCol(0);
	FlexGridSizer3->AddGrowableRow(0);
	Choicebook_EventType = new wxChoicebook(Panel3, ID_CHOICEBOOK1, wxDefaultPosition, wxDefaultSize, 0, _T("ID_CHOICEBOOK1"));
	FlexGridSizer3->Add(Choicebook_EventType, 1, wxALL|wxEXPAND, 5);
	FlexGridSizer4 = new wxFlexGridSizer(0, 3, 0, 0);
	Button_Ok = new wxButton(Panel3, ID_BUTTON1, _("Ok"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	FlexGridSizer4->Add(Button_Ok, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button_Cancel = new wxButton(Panel3, ID_BUTTON2, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	FlexGridSizer4->Add(Button_Cancel, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer3->Add(FlexGridSizer4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Panel3->SetSizer(FlexGridSizer3);
	FlexGridSizer3->Fit(Panel3);
	FlexGridSizer3->SetSizeHints(Panel3);
	Panel2 = new wxPanel(SplitterWindow1, ID_PANEL2, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL2"));
	FlexGridSizer2 = new wxFlexGridSizer(0, 2, 0, 0);
	FlexGridSizer2->AddGrowableCol(1);
	StaticText5 = new wxStaticText(Panel2, ID_STATICTEXT5, _("Name :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	FlexGridSizer2->Add(StaticText5, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl_Name = new wxTextCtrl(Panel2, ID_TEXTCTRL4, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
	FlexGridSizer2->Add(TextCtrl_Name, 1, wxALL|wxEXPAND, 5);
	StaticText1 = new wxStaticText(Panel2, ID_STATICTEXT1, _("Command :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	FlexGridSizer2->Add(StaticText1, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	Choice_Command = new wxChoice(Panel2, ID_CHOICE1, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
	Choice_Command->SetMinSize(wxSize(300,-1));
	FlexGridSizer2->Add(Choice_Command, 1, wxALL|wxEXPAND, 5);
	StaticText4 = new wxStaticText(Panel2, ID_STATICTEXT4, _("Parameter 1 :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	FlexGridSizer2->Add(StaticText4, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl_P1 = new wxTextCtrl(Panel2, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	FlexGridSizer2->Add(TextCtrl_P1, 1, wxALL|wxEXPAND, 5);
	StaticText3 = new wxStaticText(Panel2, ID_STATICTEXT3, _("Parameter 2 :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	FlexGridSizer2->Add(StaticText3, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl_P2 = new wxTextCtrl(Panel2, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	FlexGridSizer2->Add(TextCtrl_P2, 1, wxALL|wxEXPAND, 5);
	StaticText2 = new wxStaticText(Panel2, ID_STATICTEXT2, _("Parameter 3 :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	FlexGridSizer2->Add(StaticText2, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl_P3 = new wxTextCtrl(Panel2, ID_TEXTCTRL3, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	FlexGridSizer2->Add(TextCtrl_P3, 1, wxALL|wxEXPAND, 5);
	Panel2->SetSizer(FlexGridSizer2);
	FlexGridSizer2->Fit(Panel2);
	FlexGridSizer2->SetSizeHints(Panel2);
	SplitterWindow1->SplitVertically(Panel3, Panel2);
	FlexGridSizer1->Add(SplitterWindow1, 1, wxALL|wxEXPAND, 5);
	SetSizer(FlexGridSizer1);
	FlexGridSizer1->Fit(this);
	FlexGridSizer1->SetSizeHints(this);

	Connect(ID_CHOICEBOOK1,wxEVT_COMMAND_CHOICEBOOK_PAGE_CHANGED,(wxObjectEventFunction)&EventDialog::OnChoicebook_EventTypePageChanged);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&EventDialog::OnButton_OkClick);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&EventDialog::OnButton_CancelClick);
	Connect(ID_TEXTCTRL4,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&EventDialog::OnTextCtrl_NameText);
	Connect(ID_CHOICE1,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&EventDialog::OnChoice_CommandSelect);
	Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&EventDialog::OnTextCtrl_P1Text);
	Connect(ID_TEXTCTRL2,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&EventDialog::OnTextCtrl_P2Text);
	Connect(ID_TEXTCTRL3,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&EventDialog::OnTextCtrl_P3Text);
	//*)

    auto commands = xScheduleFrame::GetScheduleManager()->GetCommands();
    for (auto it = commands.begin(); it != commands.end(); ++it)
    {
        if ((*it)->IsUserSelectable())
        {
            Choice_Command->AppendString((*it)->_command);
        }
    }

    if (_eventBase == nullptr)
    {
        Choice_Command->SetSelection(0);
        Choicebook_EventType->AddPage(new EventE131Panel(Choicebook_EventType), "E131", true);
        Choicebook_EventType->AddPage(new EventDataPanel(Choicebook_EventType), "Data", true);
        Choicebook_EventType->AddPage(new EventSerialPanel(Choicebook_EventType), "Serial", false);
        Choicebook_EventType->AddPage(new EventOSCPanel(Choicebook_EventType), "OSC", false);
        Choicebook_EventType->AddPage(new EventFPPPanel(Choicebook_EventType), "FPP", false);
        Choicebook_EventType->AddPage(new EventARTNetPanel(Choicebook_EventType), "ARTNet", false);
    }
    else
    {
        std::string type = _eventBase->GetType();
        if (type == "E131")
        {
            Choicebook_EventType->AddPage(new EventE131Panel(Choicebook_EventType), "E131", true);
        }
        else if (type == "Serial")
        {
            Choicebook_EventType->AddPage(new EventSerialPanel(Choicebook_EventType), "Serial", true);
        }
        else if (type == "Data")
        {
            Choicebook_EventType->AddPage(new EventDataPanel(Choicebook_EventType), "Data", true);
        }
        else if (type == "OSC")
        {
            Choicebook_EventType->AddPage(new EventOSCPanel(Choicebook_EventType), "OSC", true);
        }
        else if (type == "FPP")
        {
            Choicebook_EventType->AddPage(new EventFPPPanel(Choicebook_EventType), "FPP", true);
        }
        else if (type == "ARTNet")
        {
            Choicebook_EventType->AddPage(new EventARTNetPanel(Choicebook_EventType), "ARTNet", true);
        }
        ((EventPanel*)Choicebook_EventType->GetPage(0))->Load(_eventBase);
        Choice_Command->SetStringSelection(_eventBase->GetCommand());
        TextCtrl_P1->SetValue(_eventBase->GetP1());
        TextCtrl_P2->SetValue(_eventBase->GetP2());
        TextCtrl_P3->SetValue(_eventBase->GetP3());
        TextCtrl_Name->SetValue(_eventBase->GetName());
    }

    SetMinSize(wxSize(800, 600));
    SetSize(800, 600);

    ValidateWindow();
}

EventDialog::~EventDialog()
{
	//(*Destroy(EventDialog)
	//*)
}

void EventDialog::OnButton_OkClick(wxCommandEvent& event)
{
    if (_eventBase == nullptr)
    {
        std::string type = Choicebook_EventType->GetChoiceCtrl()->GetStringSelection().ToStdString();
        if (type == "E131")
        {
            _eventBase = new EventE131();
        }
        else if (type == "Data")
        {
            _eventBase = new EventData();
        }
        else if (type == "Serial")
        {
            _eventBase = new EventSerial();
        }
        else if (type == "OSC")
        {
            _eventBase = new EventOSC();
        }
        else if (type == "FPP")
        {
            _eventBase = new EventFPP();
        }
        else if (type == "ARTNet")
        {
            _eventBase = new EventARTNet();
        }
    }

    EventPanel* panel = (EventPanel*)Choicebook_EventType->GetPage(Choicebook_EventType->GetSelection());
    panel->Save(_eventBase);
    _eventBase->SetCommand(Choice_Command->GetStringSelection().ToStdString());
    _eventBase->SetP1(TextCtrl_P1->GetValue().ToStdString());
    _eventBase->SetP2(TextCtrl_P2->GetValue().ToStdString());
    _eventBase->SetP3(TextCtrl_P3->GetValue().ToStdString());
    _eventBase->SetName(TextCtrl_Name->GetValue().ToStdString());

    EndDialog(wxID_OK);
}

void EventDialog::OnButton_CancelClick(wxCommandEvent& event)
{
    EndDialog(wxID_CANCEL);
}

void EventDialog::OnChoicebook_EventTypePageChanged(wxChoicebookEvent& event)
{
}

void EventDialog::OnChoice_CommandSelect(wxCommandEvent& event)
{
    Command* c = xScheduleFrame::GetScheduleManager()->GetCommand(Choice_Command->GetStringSelection().ToStdString());
    Choice_Command->SetToolTip(c->GetParametersTip());
    ValidateWindow();
}

void EventDialog::OnTextCtrl_P1Text(wxCommandEvent& event)
{
    ValidateWindow();
}

void EventDialog::OnTextCtrl_P2Text(wxCommandEvent& event)
{
    ValidateWindow();
}

void EventDialog::OnTextCtrl_P3Text(wxCommandEvent& event)
{
    ValidateWindow();
}

void EventDialog::ValidateWindow()
{
    Command* c = xScheduleFrame::GetScheduleManager()->GetCommand(Choice_Command->GetStringSelection().ToStdString());

    if (c != nullptr)
    {
        if (c->_parms == 0)
        {
            TextCtrl_P1->Enable(false);
            TextCtrl_P2->Enable(false);
            TextCtrl_P3->Enable(false);
        }
        else if (c->_parms == 1)
        {
            TextCtrl_P1->Enable(true);
            TextCtrl_P2->Enable(false);
            TextCtrl_P3->Enable(false);
        }
        else if (c->_parms == 2)
        {
            TextCtrl_P1->Enable(true);
            TextCtrl_P2->Enable(true);
            TextCtrl_P3->Enable(false);
        }
        else if (c->_parms >= 3)
        {
            TextCtrl_P1->Enable(true);
            TextCtrl_P2->Enable(true);
            TextCtrl_P3->Enable(true);
        }
    }

    EventPanel* panel = (EventPanel*)Choicebook_EventType->GetPage(Choicebook_EventType->GetSelection());
    if (TextCtrl_P1->IsEnabled() && TextCtrl_P1->GetValue().Trim().Trim(false) == "" ||
        TextCtrl_P2->IsEnabled() && TextCtrl_P2->GetValue().Trim().Trim(false) == "" ||
        TextCtrl_P3->IsEnabled() && TextCtrl_P3->GetValue().Trim().Trim(false) == "" ||
        TextCtrl_Name->GetValue().Trim().Trim(false) == "" ||
        !panel->ValidateWindow()
    )
    {
        Button_Ok->Enable(false);
    }
    else
    {
        Button_Ok->Enable();
    }
}

void EventDialog::OnTextCtrl_NameText(wxCommandEvent& event)
{
    ValidateWindow();
}