#include "stream_prototype.h"

#include "library/common/main_interface.h"

namespace Envoy {
namespace Platform {

StreamPrototype::StreamPrototype(EngineSharedPtr engine) : engine_(engine) {
  this->callbacks_ = std::make_shared<StreamCallbacks>();
}

StreamSharedPtr StreamPrototype::start() {
  auto envoy_stream = init_stream(this->engine_->engine_);
  start_stream(this->engine_->engine_, envoy_stream, this->callbacks_->asEnvoyHttpCallbacks(),
               false);
  return std::make_shared<Stream>(this->engine_->engine_, envoy_stream);
}

StreamPrototype& StreamPrototype::setOnHeaders(OnHeadersCallback closure) {
  this->callbacks_->on_headers = closure;
  return *this;
}

StreamPrototype& StreamPrototype::setOnData(OnDataCallback closure) {
  this->callbacks_->on_data = closure;
  return *this;
}

StreamPrototype& StreamPrototype::setOnTrailers(OnTrailersCallback closure) {
  this->callbacks_->on_trailers = closure;
  return *this;
}

StreamPrototype& StreamPrototype::setOnError(OnErrorCallback closure) {
  this->callbacks_->on_error = closure;
  return *this;
}

StreamPrototype& StreamPrototype::setOnComplete(OnCompleteCallback closure) {
  this->callbacks_->on_complete = closure;
  return *this;
}

StreamPrototype& StreamPrototype::setOnCancel(OnCancelCallback closure) {
  this->callbacks_->on_cancel = closure;
  return *this;
}

StreamPrototype& StreamPrototype::setOnSendWindowAvailable(OnSendWindowAvailableCallback closure) {
  this->callbacks_->on_send_window_available = closure;
  return *this;
}

} // namespace Platform
} // namespace Envoy
