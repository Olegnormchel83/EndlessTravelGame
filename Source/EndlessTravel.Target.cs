// Author: Olegnormchel. All rights reserved

using UnrealBuildTool;
using System.Collections.Generic;

public class EndlessTravelTarget : TargetRules
{
	public EndlessTravelTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V5;

		ExtraModuleNames.AddRange( new string[] { "EndlessTravel" } );
	}
}
