#include "request_headers_builder.h"

namespace Envoy {
namespace Platform {

RequestHeadersBuilder::RequestHeadersBuilder(RequestMethod request_method,
                                             const absl::string_view scheme,
                                             const absl::string_view authority,
                                             const absl::string_view path) {
  this->internalSet(":method", {requestMethodToString(request_method)});
  this->internalSet(":scheme", {std::string(scheme)});
  this->internalSet(":authority", {std::string(authority)});
  this->internalSet(":path", {std::string(path)});
}

RequestHeadersBuilder& RequestHeadersBuilder::addRetryPolicy(const RetryPolicy& retry_policy) {
  const RawHeaderMap retry_policy_headers = retry_policy.asRawHeaderMap();
  for (const auto& pair : retry_policy_headers) {
    this->internalSet(pair.first, pair.second);
  }
  return *this;
}

RequestHeadersBuilder&
RequestHeadersBuilder::addUpstreamHttpProtocol(UpstreamHttpProtocol upstream_http_protocol) {
  this->internalSet("x-envoy-mobile-upstream-protocol",
                    std::vector<std::string>{upstreamHttpProtocolToString(upstream_http_protocol)});
  return *this;
}

RequestHeaders RequestHeadersBuilder::build() const { return RequestHeaders(this->allHeaders()); }

} // namespace Platform
} // namespace Envoy
