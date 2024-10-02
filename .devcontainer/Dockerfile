FROM docker.io/library/ubuntu:24.04

# hadolint ignore=DL3009,DL3008
RUN apt-get update && \
  apt-get install -y --no-install-recommends \
  git \
  gpg \
  ca-certificates \
  meson \
  clang \
  clang-format \
  clang-tidy \
  # Needed by meson LSP
  pkg-config && \
  apt-get clean

ENV CC=clang
ENV CXX=clang++

ENTRYPOINT []
