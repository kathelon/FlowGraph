// Copyright https://github.com/MothCocoon/FlowGraph/graphs/contributors
#pragma once

#include "Input/Reply.h"
#include "Widgets/DeclarativeSyntaxSupport.h"
#include "Widgets/SCompoundWidget.h"

class FLOWEDITOR_API SFlowWelcomeWindow : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SFlowWelcomeWindow) {}
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

private:
	static void OpenExternalLink(const TCHAR* Url);

	FReply OnOpenDocs() const;
	FReply OnOpenGitHub() const;
	FReply OnOpenFlowGame() const;
	FReply OnOpenDiscord() const;
	FReply OnOpenProjectSettings() const;
};
