/* This file is part of the dynarmic project.
 * Copyright (c) 2021 MerryMage
 * SPDX-License-Identifier: 0BSD
 */

#include "dynarmic/common/assert.h"
#include "dynarmic/interface/A32/a32.h"
#include "dynarmic/interface/A32/context.h"

namespace Dynarmic::A32 {

struct Context::Impl {};

Context::Context()
        : impl(std::make_unique<Context::Impl>()) {}

Context::~Context() = default;

Context::Context(const Context& ctx)
        : impl(std::make_unique<Context::Impl>(*ctx.impl)) {}

Context::Context(Context&& ctx) noexcept
        : impl(std::move(ctx.impl)) {}

Context& Context::operator=(const Context& ctx) {
    *impl = *ctx.impl;
    return *this;
}

Context& Context::operator=(Context&& ctx) noexcept {
    impl = std::move(ctx.impl);
    return *this;
}

struct Jit::Impl {
    Impl(Jit*, A32::UserConfig) {}

    void Run() { ASSERT_FALSE("Unimplemented"); }

    void Step() { ASSERT_FALSE("Unimplemented"); }

    void ClearCache() { ASSERT_FALSE("Unimplemented"); }

    void InvalidateCacheRange(std::uint32_t start_address, std::size_t length) { ASSERT_FALSE("Unimplemented {} {}", start_address, length); }

    void Reset() { ASSERT_FALSE("Unimplemented"); }

    void HaltExecution() { ASSERT_FALSE("Unimplemented"); }

    std::array<std::uint32_t, 16>& Regs() { ASSERT_FALSE("Unimplemented"); }
    const std::array<std::uint32_t, 16>& Regs() const { ASSERT_FALSE("Unimplemented"); }
    std::array<std::uint32_t, 64>& ExtRegs() { ASSERT_FALSE("Unimplemented"); }
    const std::array<std::uint32_t, 64>& ExtRegs() const { ASSERT_FALSE("Unimplemented"); }

    std::uint32_t Cpsr() const { ASSERT_FALSE("Unimplemented"); }
    void SetCpsr(std::uint32_t value) { ASSERT_FALSE("Unimplemented {}", value); }

    std::uint32_t Fpscr() const { ASSERT_FALSE("Unimplemented"); }
    void SetFpscr(std::uint32_t value) { ASSERT_FALSE("Unimplemented {}", value); }

    Context SaveContext() const { ASSERT_FALSE("Unimplemented"); }
    void SaveContext(Context&) const { ASSERT_FALSE("Unimplemented"); }
    void LoadContext(const Context&) { ASSERT_FALSE("Unimplemented"); }

    void ClearExclusiveState() { ASSERT_FALSE("Unimplemented"); }

    void DumpDisassembly() const { ASSERT_FALSE("Unimplemented"); }
};

Jit::Jit(UserConfig conf)
        : impl(std::make_unique<Impl>(this, conf)) {}

Jit::~Jit() = default;

void Jit::Run() {
    impl->Run();
}

void Jit::Step() {
    impl->Step();
}

void Jit::ClearCache() {
    impl->ClearCache();
}

void Jit::InvalidateCacheRange(std::uint32_t start_address, std::size_t length) {
    impl->InvalidateCacheRange(start_address, length);
}

void Jit::Reset() {
    impl->Reset();
}

void Jit::HaltExecution() {
    impl->HaltExecution();
}

std::array<std::uint32_t, 16>& Jit::Regs() {
    return impl->Regs();
}

const std::array<std::uint32_t, 16>& Jit::Regs() const {
    return impl->Regs();
}

std::array<std::uint32_t, 64>& Jit::ExtRegs() {
    return impl->ExtRegs();
}

const std::array<std::uint32_t, 64>& Jit::ExtRegs() const {
    return impl->ExtRegs();
}

std::uint32_t Jit::Cpsr() const {
    return impl->Cpsr();
}

void Jit::SetCpsr(std::uint32_t value) {
    impl->SetCpsr(value);
}

std::uint32_t Jit::Fpscr() const {
    return impl->Fpscr();
}

void Jit::SetFpscr(std::uint32_t value) {
    impl->SetFpscr(value);
}

Context Jit::SaveContext() const {
    return impl->SaveContext();
}

void Jit::SaveContext(Context& ctx) const {
    impl->SaveContext(ctx);
}

void Jit::LoadContext(const Context& ctx) {
    impl->LoadContext(ctx);
}

void Jit::ClearExclusiveState() {
    impl->ClearExclusiveState();
}

void Jit::DumpDisassembly() const {
    impl->DumpDisassembly();
}

}  // namespace Dynarmic::A32
