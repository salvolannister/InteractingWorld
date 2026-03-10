// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class InteractingWorld : ModuleRules
{
	public InteractingWorld(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "UMG" });
	}
}
