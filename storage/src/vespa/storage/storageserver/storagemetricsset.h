// Copyright 2017 Yahoo Holdings. Licensed under the terms of the Apache 2.0 license. See LICENSE in the project root.

#pragma once

#include "tls_statistics_metrics_wrapper.h"

#include <vespa/metrics/metrics.h>

namespace storage {

class MessageMemoryUseMetricSet : public metrics::MetricSet
{
public:
    metrics::LongValueMetric total;
    metrics::LongValueMetric lowpri;
    metrics::LongValueMetric normalpri;
    metrics::LongValueMetric highpri;
    metrics::LongValueMetric veryhighpri;

    MessageMemoryUseMetricSet(metrics::MetricSet* owner);
    ~MessageMemoryUseMetricSet();
};

struct DocumentSerializationMetricSet : public metrics::MetricSet
{
    metrics::LongCountMetric usedCachedSerializationCount;
    metrics::LongCountMetric compressedDocumentCount;
    metrics::LongCountMetric compressionDidntHelpCount;
    metrics::LongCountMetric uncompressableCount;
    metrics::LongCountMetric serializedUncompressed;
    metrics::LongCountMetric inputWronglySerialized;

    DocumentSerializationMetricSet(metrics::MetricSet* owner);
    ~DocumentSerializationMetricSet();
};

struct StorageMetricSet : public metrics::MetricSet
{
    metrics::LongValueMetric memoryUse;
    MessageMemoryUseMetricSet memoryUse_messages;
    metrics::LongValueMetric memoryUse_visiting;
    DocumentSerializationMetricSet documentSerialization;

    TlsStatisticsMetricsWrapper tls_metrics;

    StorageMetricSet();
    ~StorageMetricSet();
    void updateMetrics();
};

} // storage

