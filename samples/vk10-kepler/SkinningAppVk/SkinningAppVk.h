//----------------------------------------------------------------------------------
// File:        vk10-kepler\SkinningAppVk/SkinningAppVk.h
// SDK Version: v3.00 
// Email:       gameworks@nvidia.com
// Site:        http://developer.nvidia.com/
//
// Copyright (c) 2014-2015, NVIDIA CORPORATION. All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
//  * Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
//  * Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
//  * Neither the name of NVIDIA CORPORATION nor the names of its
//    contributors may be used to endorse or promote products derived
//    from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ``AS IS'' AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
// PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR
// CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
// EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
// PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
// OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
//----------------------------------------------------------------------------------
#ifndef SKINNING_APP_VK_H
#define SKINNING_APP_VK_H

#include "NvVkUtil/NvSampleAppVK.h"
#include "NV/NvMath.h"
#include "SkinnedMesh.h"

class SkinningAppVk : public NvSampleAppVK, public NvGLDrawCallbacks
{
public:
	SkinningAppVk();
	~SkinningAppVk();

	void initRendering(void);


	void shutdownRendering(void);

	void initUI(void);
	void draw(void);
	void reshape(int32_t width, int32_t height);

	void configurationCallback(NvVKConfiguration& config);

	virtual void initGLResources(NvAppContextGL* gl);
	virtual void drawGL(NvAppContextGL* gl);

private:
	void computeBones(float t, SkinnedMesh::UBOBlock& ubo);

	void updateRenderCommands();

	// basic rendering resources
	VkPipelineLayout mPipelineLayout;
	VkPipeline mPipeline;


	// application state
	SkinnedMesh      mMesh;

	bool             mSingleBoneSkinning;
	bool             mPauseTime;

	float            mTime;
	float            mTimeScalar;

	uint32_t         mRenderMode;        // 0: Render Color   1: Render Normals    2: Render Weights
};

#endif
