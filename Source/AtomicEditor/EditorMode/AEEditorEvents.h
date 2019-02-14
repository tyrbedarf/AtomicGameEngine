//
// Copyright (c) 2014-2016 THUNDERBEAST GAMES LLC
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//

#pragma once

#include <Atomic/Core/Object.h>

using namespace Urho3D;

namespace AtomicEditor
{

	static const unsigned FINDTEXT_FLAG_NONE = 0x0;
	static const unsigned FINDTEXT_FLAG_CASESENSITIVE = 0x1;
	static const unsigned FINDTEXT_FLAG_WHOLEWORD = 0x2;
	static const unsigned FINDTEXT_FLAG_WRAP = 0x4;
	static const unsigned FINDTEXT_FLAG_NEXT = 0x8;
	static const unsigned FINDTEXT_FLAG_PREV = 0x10;


	// emitted when the play button has been pressed in the editor, but the player has not yet started
	URHO3D_EVENT(E_EDITORPLAYREQUEST, EditorPlayRequest)
	{
		URHO3D_PARAM(P_MODE, Mode);    // uint (AEPlayerMode)
	}

	// Called when the active resource editor has changed
	URHO3D_EVENT(E_EDITORRESOURCEEDITORCHANGED, EditorResourceEditorChanged)
	{
		URHO3D_PARAM(P_RESOURCEEDITOR, ResourceEditor); // ResourceEditor*
	}

	// emitted once play has started
	URHO3D_EVENT(E_EDITORPLAYERSTARTED, EditorPlayerStarted)
	{
		URHO3D_PARAM(P_MODE, Mode);    // uint (AEPlayerMode)
	}

	// emitted once player has paused
	URHO3D_EVENT(E_EDITORPLAYERPAUSED, EditorPlayerPaused)
	{

	}

	// emitted once paused player has resumed
	URHO3D_EVENT(E_EDITORPLAYERRESUMED, EditorPlayerResumed)
	{

	}

	// emitted once play has stopped
	URHO3D_EVENT(E_EDITORPLAYERSTOPPED, EditorPlayerStopped)
	{

	}

	// NOT CURRENTLY WIRED
	URHO3D_EVENT(E_EDITORBUILD, EditorBuild)
	{
		URHO3D_PARAM(P_PLATFORM, Platform);      // string
		URHO3D_PARAM(P_BUILDPATH, BuildPath);    // string
	}


	// TODO: consolidate all errors to use this message

	static const unsigned EDITOR_MODALERROR = 0x1;
	static const unsigned EDITOR_MODALINFO = 0x2;

	// emitted to display a modal message in the editor
	URHO3D_EVENT(E_EDITORMODAL, EditorModal)
	{
		URHO3D_PARAM(P_TYPE, Type);      // uint (Type can be EDITOR_MODALERROR, EDITOR_MODAL_INFOT)
		URHO3D_PARAM(P_TITLE, Title);      // string (for modal errors, title text)
		URHO3D_PARAM(P_MESSAGE, Message);    // string (for modal errors, error text)
	}

	// emitted when a Scene editor gains focus.  Could be null.
	URHO3D_EVENT(E_EDITORACTIVESCENEEDITORCHANGE, EditorActiveSceneEditorChange)
	{
		URHO3D_PARAM(P_SCENEEDITOR, SceneEditor);  // SceneEditor3D pointer
	}

	// NOTE: This is not triggered by anything
	URHO3D_EVENT(E_EDITORSCENECLOSED, EditorSceneClosed)
	{
		URHO3D_PARAM(P_SCENE, Scene); // Scene pointer
	}

	// emitted when a subprocess logs information to the console
	URHO3D_EVENT(E_SUBPROCESSOUTPUT, SubprocessOutput)
	{
		URHO3D_PARAM(P_TEXT, Text);      // string
	}

	// emitted when a subprocess has completed
	URHO3D_EVENT(E_SUBPROCESSCOMPLETE, SubprocessComplete)
	{
		URHO3D_PARAM(P_PROCESSKEY, ProcessKey); // unsigned
		URHO3D_PARAM(P_RETCODE, RetCode);      // int (return code of process)
	}

	// Command called to load a new project
	URHO3D_EVENT(E_EDITORLOADPROJECT, EditorLoadProject)
	{
		URHO3D_PARAM(P_PATH, Path);     // string
	}

	// emitted once a content folder has been refreshed
	URHO3D_EVENT(E_CONTENTFOLDERCHANGED, ContentFolderChanged)
	{
		URHO3D_PARAM(P_PATH, Path);     // string
	}

	// emitted when the editor has been requested to close the current project.
	URHO3D_EVENT(E_EDITORCLOSEPROJECT, EditorCloseProject)
	{

	}

	// emitted once a project has completed closing
	URHO3D_EVENT(E_EDITORPROJECTCLOSED, EditorProjectClosed)
	{

	}

	// command to save all the open editors
	URHO3D_EVENT(E_EDITORSAVEALLRESOURCES, EditorSaveAllResources)
	{

	}

	// command to save a specific resource
	URHO3D_EVENT(E_EDITORSAVERESOURCE, EditorSaveResource)
	{
		URHO3D_PARAM(P_PATH, Path);     // string full path of the current resource
	}

	// emitted once the resource has been saved
	URHO3D_EVENT(E_EDITORSAVERESOURCENOTIFICATION, EditorSaveResourceNotification)
	{
		URHO3D_PARAM(P_PATH, Path);     // string
	}

	// emitted when a resource gains focus
	URHO3D_EVENT(E_EDITOREDITRESOURCE, EditorEditResource)
	{
		URHO3D_PARAM(P_PATH, Path);     // string
		URHO3D_PARAM(P_LINENUMBER, LineNumber); // int optional
	}

	// command to delete a resource
	URHO3D_EVENT(E_EDITORDELETERESOURCE, EditorDeleteResource)
	{
		URHO3D_PARAM(P_PATH, Path);     // string
	}

	// emitted once the resource has been deleted
	URHO3D_EVENT(E_EDITORDELETERESOURCENOTIFICATION, EditorDeleteResourceNotification)
	{
		URHO3D_PARAM(P_PATH, Path);     // string
	}

	// emitted when a resource has been renamed
	URHO3D_EVENT(E_EDITORRENAMERESOURCENOTIFICATION, EditorRenameResourceNotification)
	{
		URHO3D_PARAM(P_PATH, Path);     // string (full path of the old resource)
		URHO3D_PARAM(P_NEWPATH, NewPath);   // string (full path of the new resource)
		URHO3D_PARAM(P_NEWNAME, NewName);    // string (new name of resource)
		URHO3D_PARAM(P_ASSET, Asset);       // ToolCore.Asset pointer
	}

	// emitted when user preferences have been changed
	URHO3D_EVENT(E_USERPREFERENCESCHANGEDNOTIFICATION, UserPreferencesChangedNotification)
	{
		URHO3D_PARAM(P_PROJECTPREFERENCES, ProjectPreferences);  // string (JSON object)
		URHO3D_PARAM(P_APPLICATIONPREFERENCES, ApplicationPreferences);        // string (JSON object)
	}

	// emitted when an item is selected in a scene
	URHO3D_EVENT(E_INSPECTORPROJECTREFERENCE, InspectorProjectReference)
	{
		URHO3D_PARAM(P_PATH, Path);     // string (Full path of the resource to edit)
	}

	// emitted when a component attribute has been changed
	URHO3D_EVENT(E_ATTRIBUTEEDITRESOURCECHANGED, AttributeEditResourceChanged)
	{
		URHO3D_PARAM(P_ATTRINFOEDIT, AttrInfoEdit); // AttrbuteInfoEdit window
		URHO3D_PARAM(P_RESOURCE, Resource); // Resource pointer
	}

	// emitted when the built in player logs something
	URHO3D_EVENT(E_EDITORPLAYERLOG, EditorPlayerLog)
	{
		URHO3D_PARAM(P_MESSAGE, Message);   // string
		URHO3D_PARAM(P_LEVEL, Level);       // int
	}

	// emitted right before a project is unloaded
	URHO3D_EVENT(E_PROJECTUNLOADEDNOTIFICATION, ProjectUnloadedNotification)
	{

	}

	// command to load a new project
	URHO3D_EVENT(E_REQUESTPROJECTLOAD, RequestProjectLoad)
	{
		URHO3D_PARAM(P_PATH, Path);     // string (Full path to the .atomic file)
	}

	// emitted once a project has been loaded
	URHO3D_EVENT(E_LOADPROJECTNOTIFICATION, LoadProjectNotification)
	{
		URHO3D_PARAM(P_PATH, Path);     // string (Full path to the .atomic file)
	}

}
