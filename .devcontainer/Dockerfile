FROM docker.io/library/ubuntu:24.04

RUN apt-get update && \
  apt-get install -y --no-install-recommends \
  ca-certificates \
  git \
  gpg \
  meson \
  clang \
  # Needed by meson LSP
  pkg-config \
  clang-format \
  clang-tidy && \
  apt-get clean

ENV CC=clang
ENV CXX=clang++

ENTRYPOINT []
