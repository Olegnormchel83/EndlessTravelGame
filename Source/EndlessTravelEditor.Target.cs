// Author: Olegnormchel. All rights reserved

using UnrealBuildTool;
using System.Collections.Generic;

public class EndlessTravelEditorTarget : TargetRules
{
	public EndlessTravelEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V5;

		ExtraModuleNames.AddRange( new string[] { "EndlessTravel" } );
	}
}
