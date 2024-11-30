// Copyright TPGames

using UnrealBuildTool;
using System.Collections.Generic;

public class RadianceEditorTarget : TargetRules
{
	public RadianceEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V5;

		ExtraModuleNames.AddRange( new string[] { "Radiance" } );
	}
}