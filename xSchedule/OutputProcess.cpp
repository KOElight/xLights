#include "OutputProcess.h"
#include <wx/xml/xml.h>
#include <wx/wxcrt.h>
#include "OutputProcessDim.h"
#include "OutputProcessDimWhite.h"
#include "OutputProcessSet.h"
#include "OutputProcessRemap.h"

OutputProcess::OutputProcess(wxXmlNode* node)
{
    _changeCount = 0;
    _lastSavedChangeCount = 0;
    _startChannel = wxAtol(node->GetAttribute("StartChannel", "1"));
}

OutputProcess::OutputProcess(const OutputProcess& op)
{
    _changeCount = op._changeCount;
    _lastSavedChangeCount = op._lastSavedChangeCount;
    _startChannel = op._startChannel;
}

OutputProcess::OutputProcess()
{
    _changeCount = 1;
    _lastSavedChangeCount = 0;
    _startChannel = 1;
}

OutputProcess::OutputProcess(size_t startChannel)
{
    _changeCount = 1;
    _lastSavedChangeCount = 0;
    _startChannel = startChannel;
}

void OutputProcess::Save(wxXmlNode* node)
{
    node->AddAttribute("StartChannel", wxString::Format(wxT("%i"), _startChannel));
}

OutputProcess* OutputProcess::CreateFromXml(wxXmlNode* node)
{
    if (node->GetName() == "OPDim")
    {
        return new OutputProcessDim(node);
    }
    else if (node->GetName() == "OPDimWhite")
    {
        return new OutputProcessDimWhite(node);
    }
    else if (node->GetName() == "OPSet")
    {
        return new OutputProcessSet(node);
    }
    else if (node->GetName() == "OPRemap")
    {
        return new OutputProcessRemap(node);
    }
}