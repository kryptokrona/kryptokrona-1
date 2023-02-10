// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
// Copyright (c) 2018, The TurtleCoin Developers
//
// Please see the included LICENSE file for more information.

#pragma once

#include "crypto_types.h"

#include "httplib.h"

#include <optional>

#include <syst/context_group.h>
#include <syst/dispatcher.h>
#include <syst/event.h>

class BlockchainMonitor
{
public:
    BlockchainMonitor(
        syst::Dispatcher &dispatcher,
        const size_t pollingInterval,
        const std::shared_ptr<httplib::Client> httpClient);

    void waitBlockchainUpdate();
    void stop();

private:
    syst::Dispatcher &m_dispatcher;
    size_t m_pollingInterval;
    bool m_stopped;
    syst::ContextGroup m_sleepingContext;

    std::optional<Crypto::Hash> requestLastBlockHash();

    std::shared_ptr<httplib::Client> m_httpClient = nullptr;
};
