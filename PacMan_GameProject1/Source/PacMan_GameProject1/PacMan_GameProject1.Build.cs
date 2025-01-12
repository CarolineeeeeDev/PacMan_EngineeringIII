// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class PacMan_GameProject1 : ModuleRules
{
	public PacMan_GameProject1(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
		PrivateDependencyModuleNames.AddRange(new string[] { "AIModule" });
	}
}
