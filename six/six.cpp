// Unless explicitly stated otherwise all files in this repository are licensed
// under the Apache License Version 2.0.
// This product includes software developed at Datadog (https://www.datadoghq.com/).
// Copyright 2019 Datadog, Inc.
#include <six.h>

const char *Six::getExtensionModuleName(six_module_t m) {
    switch (m) {
    case DATADOG_AGENT_SIX__UTIL:
        return datadog_agent_six__util;
    case DATADOG_AGENT_SIX_AGGREGATOR:
        return datadog_agent_six_aggregator;
    case DATADOG_AGENT_SIX_CONTAINERS:
        return datadog_agent_six_containers;
    case DATADOG_AGENT_SIX_DATADOG_AGENT:
        return datadog_agent_six_datadog_agent;
    case DATADOG_AGENT_SIX_KUBEUTIL:
        return datadog_agent_six_kubeutil;
    case DATADOG_AGENT_SIX_TAGGER:
        return datadog_agent_six_tagger;
    case DATADOG_AGENT_SIX_UTIL:
        return datadog_agent_six_util;
    default:
        return datadog_agent_six_unknown;
    }
}

const char *Six::getUnknownModuleName() { return datadog_agent_six_unknown; }

void Six::setError(const std::string &msg) {
    _error_mtx.lock();
    _error = msg;
    _error_mtx.unlock();
}

void Six::clearError() {
    _error_mtx.lock();
    _error = "";
    _error_mtx.unlock();
}

std::string Six::getError() const {
    _error_mtx.lock();
    std::string ret = _error;
    _error_mtx.unlock();
    return ret;
}

bool Six::hasError() const {
    bool ret;

    _error_mtx.lock();
    ret = _error != "";
    _error_mtx.unlock();

    return ret;
}
