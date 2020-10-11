/*
			This file is part of:
				NoahFrame
			https://github.com/ketoo/NoahGameFrame

   Copyright 2009 - 2020 NoahFrame(NoahGameFrame)

   File creator: lvsheng.huang

   NoahFrame is open-source software and you can redistribute it and/or modify
   it under the terms of the License; besides, anyone who use this file/software must include this copyright announcement.

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

	   http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

#include "NFGameView.h"
#include "NFUIModule.h"


NFGameView::NFGameView(NFIPluginManager* p, NFViewType vt) : NFIView(p, vt, GET_CLASS_NAME(NFGameView))
{
    m_pKernelModule = p->FindModule<NFIKernelModule>();

    mNodeSystem.AddNode(m_pKernelModule->CreateGUID(), "test0");
    mNodeSystem.AddNode(m_pKernelModule->CreateGUID(), "test1", NFVector2(0, -100));
    mNodeSystem.AddNode(m_pKernelModule->CreateGUID(), "test1", NFVector2(50, 100));
}

bool NFGameView::Execute()
{
	//1. the project root folder is NFDataCfg
    if (ImGui::Button("return to center"))
    {
        mNodeSystem.ResetToCenter();

    }

 

    mNodeSystem.Execute();

	return false;
}