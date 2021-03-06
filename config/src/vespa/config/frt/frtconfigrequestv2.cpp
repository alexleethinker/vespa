// Copyright 2017 Yahoo Holdings. Licensed under the terms of the Apache 2.0 license. See LICENSE in the project root.
#include "frtconfigrequestv2.h"
#include "frtconfigresponsev2.h"
#include "connection.h"
#include <vespa/config/common/trace.h>
#include <vespa/config/common/vespa_version.h>

using namespace config::protocol;

namespace config {

FRTConfigRequestV2::FRTConfigRequestV2(Connection * connection,
                                       const ConfigKey & key,
                                       const vespalib::string & configMd5,
                                       int64_t currentGeneration,
                                       int64_t wantedGeneration,
                                       const vespalib::string & hostName,
                                       int64_t serverTimeout,
                                       const Trace & trace)
    : SlimeConfigRequest(connection, key, configMd5, currentGeneration, wantedGeneration, hostName, serverTimeout, trace, VespaVersion::getCurrentVersion(), 2, CompressionType::UNCOMPRESSED, "config.v2.getConfig")
{
}



ConfigResponse::UP
FRTConfigRequestV2::createResponse(FRT_RPCRequest * request) const
{
    return ConfigResponse::UP(new FRTConfigResponseV2(request));
}

}
