#pragma once

#include <string>

#include "headers_builder.h"
#include "request_headers.h"
#include "request_method.h"
#include "retry_policy.h"
#include "upstream_http_protocol.h"

namespace Envoy {
namespace Platform {

class RequestHeaders;
struct RetryPolicy;

class RequestHeadersBuilder : public HeadersBuilder {
public:
  RequestHeadersBuilder(RequestMethod request_method, const absl::string_view scheme,
                        const absl::string_view authority, const absl::string_view path);

  RequestHeadersBuilder& addRetryPolicy(const RetryPolicy& retry_policy);
  RequestHeadersBuilder& addUpstreamHttpProtocol(UpstreamHttpProtocol upstream_http_protocol);

  RequestHeaders build() const;
};

using RequestHeadersBuilderSharedPtr = std::shared_ptr<RequestHeadersBuilder>;

} // namespace Platform
} // namespace Envoy
