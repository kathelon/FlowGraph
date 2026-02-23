// Copyright https://github.com/MothCocoon/FlowGraph/graphs/contributors

#include "Utils/SFlowWelcomeWindow.h"

#include "FlowEditorStyle.h"

#include "HAL/PlatformProcess.h"
#include "ISettingsModule.h"
#include "Modules/ModuleManager.h"
#include "Styling/AppStyle.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Images/SImage.h"
#include "Widgets/Layout/SBorder.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Layout/SUniformGridPanel.h"
#include "Widgets/SBoxPanel.h"
#include "Widgets/Text/STextBlock.h"

#define LOCTEXT_NAMESPACE "SFlowWelcomeWindow"

namespace FlowWelcomeWindow
{
	static const TCHAR* DocsUrl = TEXT("https://mothcocoon.github.io/FlowGraph/");
	static const TCHAR* GitHubUrl = TEXT("https://github.com/MothCocoon/FlowGraph");
	static const TCHAR* FlowGameUrl = TEXT("https://github.com/MothCocoon/FlowGame");
	static const TCHAR* DiscordUrl = TEXT("https://discord.gg/Xmtr6GhbmW");
}

void SFlowWelcomeWindow::Construct(const FArguments& InArgs)
{
	ChildSlot
	[
		SNew(SBorder)
			.BorderImage(FAppStyle::GetBrush("ToolPanel.GroupBorder"))
			.Padding(16.f)
			[
				SNew(SBox)
					.MinDesiredWidth(760.f)
					[
						SNew(SVerticalBox)
						+ SVerticalBox::Slot()
							.AutoHeight()
							[
								SNew(STextBlock)
									.Font(FAppStyle::GetFontStyle("HeadingMedium"))
									.Text(LOCTEXT("WelcomeTitle", "Welcome to Flow Graph"))
							]
						+ SVerticalBox::Slot()
							.AutoHeight()
							.Padding(0.f, 8.f, 0.f, 0.f)
							[
								SNew(STextBlock)
									.AutoWrapText(true)
									.Text(LOCTEXT("WelcomeDescription", "Thanks for enabling the Flow Graph plugin. Use the resources below to quickly get started."))
							]
						+ SVerticalBox::Slot()
							.AutoHeight()
							.Padding(0.f, 14.f, 0.f, 0.f)
							[
								SNew(SBorder)
									.BorderImage(FAppStyle::GetBrush("ToolPanel.GroupBorder"))
									.Padding(12.f)
									[
										SNew(SVerticalBox)
										+ SVerticalBox::Slot()
											.AutoHeight()
											[
												SNew(STextBlock)
													.Font(FAppStyle::GetFontStyle("NormalFontBold"))
													.ColorAndOpacity(FLinearColor(1.f, 0.75f, 0.1f, 1.f))
													.Text(LOCTEXT("ImportantTitle", "Important Setup"))
											]
										+ SVerticalBox::Slot()
											.AutoHeight()
											.Padding(0.f, 8.f, 0.f, 0.f)
											[
												SNew(STextBlock)
													.AutoWrapText(true)
													.Text(LOCTEXT("ImportantBullet1", "- Open Project Settings."))
											]
										+ SVerticalBox::Slot()
											.AutoHeight()
											.Padding(0.f, 4.f, 0.f, 0.f)
											[
												SNew(STextBlock)
													.AutoWrapText(true)
													.Text(LOCTEXT("ImportantBullet2", "- Set World Settings class to Flow World Settings."))
											]
										+ SVerticalBox::Slot()
											.AutoHeight()
											.Padding(0.f, 4.f, 0.f, 0.f)
											[
												SNew(STextBlock)
													.AutoWrapText(true)
													.Text(LOCTEXT("ImportantBullet3", "- Restart the editor."))
											]
									]
							]
						+ SVerticalBox::Slot()
							.AutoHeight()
							.Padding(0.f, 10.f, 0.f, 0.f)
							[
								SNew(SButton)
									.OnClicked(this, &SFlowWelcomeWindow::OnOpenProjectSettings)
									[
										SNew(SHorizontalBox)
										+ SHorizontalBox::Slot()
											.AutoWidth()
											.VAlign(VAlign_Center)
											[
												SNew(SImage)
													.Image(FAppStyle::Get().GetBrush("Icons.Settings"))
											]
										+ SHorizontalBox::Slot()
											.AutoWidth()
											.Padding(6.f, 0.f, 0.f, 0.f)
											.VAlign(VAlign_Center)
											[
												SNew(STextBlock)
													.Text(LOCTEXT("OpenProjectSettingsButton", "Open Project Settings"))
											]
									]
							]
						+ SVerticalBox::Slot()
							.AutoHeight()
							.Padding(0.f, 16.f, 0.f, 0.f)
							[
								SNew(STextBlock)
									.Text(LOCTEXT("ResourcesTitle", "Resources"))
							]
						+ SVerticalBox::Slot()
							.AutoHeight()
							.Padding(0.f, 8.f, 0.f, 0.f)
							[
								SNew(SBorder)
									.BorderImage(FAppStyle::GetBrush("ToolPanel.GroupBorder"))
									.Padding(10.f)
									[
										SNew(SUniformGridPanel)
											.SlotPadding(FMargin(8.f))
											.MinDesiredSlotWidth(200.f)
											.MinDesiredSlotHeight(34.f)

											+ SUniformGridPanel::Slot(0, 0)
											[
												SNew(SButton)
													.OnClicked(this, &SFlowWelcomeWindow::OnOpenDocs)
													[
														SNew(SHorizontalBox)
														+ SHorizontalBox::Slot()
															.AutoWidth()
															.VAlign(VAlign_Center)
															[
																SNew(SImage)
																	.Image(FFlowEditorStyle::GetBrush("FlowWelcome.Docs"))
															]
														+ SHorizontalBox::Slot()
															.AutoWidth()
															.Padding(6.f, 0.f, 0.f, 0.f)
															.VAlign(VAlign_Center)
															[
																SNew(STextBlock)
																	.Text(LOCTEXT("DocsButton", "Docs"))
															]
													]
											]

											+ SUniformGridPanel::Slot(1, 0)
											[
												SNew(SButton)
													.OnClicked(this, &SFlowWelcomeWindow::OnOpenGitHub)
													[
														SNew(SHorizontalBox)
														+ SHorizontalBox::Slot()
															.AutoWidth()
															.VAlign(VAlign_Center)
															[
																SNew(SImage)
																	.Image(FFlowEditorStyle::GetBrush("FlowWelcome.GitHub"))
															]
														+ SHorizontalBox::Slot()
															.AutoWidth()
															.Padding(6.f, 0.f, 0.f, 0.f)
															.VAlign(VAlign_Center)
															[
																SNew(STextBlock)
																	.Text(LOCTEXT("FlowGraphButton", "Flow Graph"))
															]
													]
											]

											+ SUniformGridPanel::Slot(0, 1)
											[
												SNew(SButton)
													.OnClicked(this, &SFlowWelcomeWindow::OnOpenFlowGame)
													[
														SNew(SHorizontalBox)
														+ SHorizontalBox::Slot()
															.AutoWidth()
															.VAlign(VAlign_Center)
															[
																SNew(SImage)
																	.Image(FFlowEditorStyle::GetBrush("FlowWelcome.GitHub"))
															]
														+ SHorizontalBox::Slot()
															.AutoWidth()
															.Padding(6.f, 0.f, 0.f, 0.f)
															.VAlign(VAlign_Center)
															[
																SNew(STextBlock)
																	.Text(LOCTEXT("FlowGameButton", "Flow Game"))
															]
													]
											]

											+ SUniformGridPanel::Slot(1, 1)
											[
												SNew(SButton)
													.OnClicked(this, &SFlowWelcomeWindow::OnOpenDiscord)
													[
														SNew(SHorizontalBox)
														+ SHorizontalBox::Slot()
															.AutoWidth()
															.VAlign(VAlign_Center)
															[
																SNew(SImage)
																	.Image(FFlowEditorStyle::GetBrush("FlowWelcome.Discord"))
															]
														+ SHorizontalBox::Slot()
															.AutoWidth()
															.Padding(6.f, 0.f, 0.f, 0.f)
															.VAlign(VAlign_Center)
															[
																SNew(STextBlock)
																	.Text(LOCTEXT("DiscordButton", "Discord"))
															]
													]
											]
									]
							]
					]
			]
	];
}

void SFlowWelcomeWindow::OpenExternalLink(const TCHAR* Url)
{
	FPlatformProcess::LaunchURL(Url, nullptr, nullptr);
}

FReply SFlowWelcomeWindow::OnOpenDocs() const
{
	OpenExternalLink(FlowWelcomeWindow::DocsUrl);
	return FReply::Handled();
}

FReply SFlowWelcomeWindow::OnOpenGitHub() const
{
	OpenExternalLink(FlowWelcomeWindow::GitHubUrl);
	return FReply::Handled();
}

FReply SFlowWelcomeWindow::OnOpenFlowGame() const
{
	OpenExternalLink(FlowWelcomeWindow::FlowGameUrl);
	return FReply::Handled();
}

FReply SFlowWelcomeWindow::OnOpenDiscord() const
{
	OpenExternalLink(FlowWelcomeWindow::DiscordUrl);
	return FReply::Handled();
}

FReply SFlowWelcomeWindow::OnOpenProjectSettings() const
{
	FModuleManager::LoadModuleChecked<ISettingsModule>("Settings").ShowViewer("Project", "Engine", "General");
	return FReply::Handled();
}

#undef LOCTEXT_NAMESPACE
