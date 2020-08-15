#pragma once

#include "Nodes/Notifies/FlowNode_NotifyBase.h"
#include "FlowNode_NotifyActor.generated.h"

/**
 * Notify Actor
 */
UCLASS(meta = (DisplayName = "Notify Actor"))
class FLOW_API UFlowNode_NotifyActor : public UFlowNode_NotifyBase
{
	GENERATED_UCLASS_BODY()
	
protected:
	virtual void ExecuteInput(const FName& PinName) override;
};