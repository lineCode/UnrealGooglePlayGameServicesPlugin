// Copyright Epic Games, Inc. All Rights Reserved.

using System.IO;
using UnrealBuildTool;

public class GooglePlayPlugin : ModuleRules
{
	public GooglePlayPlugin(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;


		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"Projects",
				"CoreUObject",
				"Engine",
				"InputCore"
			}
			);
		
		if (Target.Platform == UnrealTargetPlatform.Android)
		{
			PrivateDependencyModuleNames.AddRange(new string[] { "Launch" });
			string PluginPath = Utils.MakePathRelativeTo(ModuleDirectory, Target.RelativeEnginePath);
			AdditionalPropertiesForReceipt.Add("AndroidPlugin", Path.Combine(PluginPath, "GooglePlay_APL.xml"));
		}
	}
}
