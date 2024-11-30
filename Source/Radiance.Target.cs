// Copyright TPGames

using UnrealBuildTool;
using System.Collections.Generic;

public class RadianceTarget : TargetRules
{
	public RadianceTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V5;

		ExtraModuleNames.AddRange( new string[] { "Radiance" } );
	}
}
