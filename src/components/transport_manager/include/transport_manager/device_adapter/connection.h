/**
 * \file connection.h
 * \brief Connection class header.
 * Copyright (c) 2013, Ford Motor Company
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following
 * disclaimer in the documentation and/or other materials provided with the
 * distribution.
 *
 * Neither the name of the Ford Motor Company nor the names of its contributors
 * may be used to endorse or promote products derived from this software
 * without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef SRC_COMPONENTS_TRANSPORT_MANAGER_INCLUDE_TRANSPORT_MANAGER_DEVICE_ADAPTER_CONNECTION_H_
#define SRC_COMPONENTS_TRANSPORT_MANAGER_INCLUDE_TRANSPORT_MANAGER_DEVICE_ADAPTER_CONNECTION_H_

#include "utils/shared_ptr.h"
#include "transport_manager/device_adapter/device_adapter.h"

using utils::SharedPtr;

/**
 * @brief Transport manager namespace.
 */
namespace transport_manager {

/**
 * @brief Device adapter namespace, part of transport manager namespace.
 */
namespace device_adapter {

/**
 * @brief Application connection.
 **/
class Connection {
 public:
  /**
   * @brief Constructor.
   */
  Connection() {}
  /**
   * @brief Destructor.
   **/
  virtual ~Connection() {}

  /**
   * @brief Send data.
   *
   * @param message smart pointer to raw message
   *
   * @return Error information about possible reason of sending data failure.
   */
  virtual DeviceAdapter::Error sendData(RawMessageSptr message) = 0;

  /**
   * @brief End the current connection.
   */
  virtual DeviceAdapter::Error disconnect() = 0;
};

typedef utils::SharedPtr<Connection> ConnectionSptr;

}  // namespace device_adapter
}  // namespace transport_manager

#endif /* CONNECTION_H_ */