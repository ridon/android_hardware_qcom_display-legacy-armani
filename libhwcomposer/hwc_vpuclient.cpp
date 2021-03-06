/*
* Copyright (c) 2013 The Linux Foundation. All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are
* met:
*    * Redistributions of source code must retain the above copyright
*      notice, this list of conditions and the following disclaimer.
*    * Redistributions in binary form must reproduce the above
*      copyright notice, this list of conditions and the following
*      disclaimer in the documentation and/or other materials provided
*      with the distribution.
*    * Neither the name of The Linux Foundation. nor the names of its
*      contributors may be used to endorse or promote products derived
*      from this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
* WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
* ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
* BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
* SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
* BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
* WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
* OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
* IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include <dlfcn.h>
#include "hwc_vpuclient.h"
#include "hwc_utils.h"
#include <vpu/vpu.h>


using namespace vpu;
namespace qhwc {

VPUClient::VPUClient()
{
    mVPULib = dlopen("libvpu.so", RTLD_NOW);
    VPU* (*init)();
    *(void **) &init =  dlsym(mVPULib, "getObject");
    if(init)
        mVPU = init();
    else
        mVPU = NULL;
}

VPUClient::~VPUClient()
{
    void (*destroy) (VPU*);
    *(void **) &destroy = dlsym(mVPULib, "deleteObject");
    dlclose(mVPULib);
}

int VPUClient::prepare(hwc_context_t *ctx,
                                hwc_display_contents_1_t* list)
{
    int err = 0;
    if(!mVPU)
        return err;
    // * Check VPU status
    // * Check session availability
    // * Other individual checks
    // Do not pass hwc context/list
    // Mark buffers to be drawn for VPU
    return err;
}

int VPUClient::draw(hwc_context_t *ctx,
                             hwc_display_contents_1_t* list)
{
    int err = 0;
    if(!mVPU)
        return err;
    // Queue buffers to VPU
    return err;
}

int VPUClient::processCommand(uint32_t command, uint32_t setting)
{
    if(!mVPU)
        return 0;
    return mVPU->processCommand(command, setting);
}

}; // namespace qhwc
