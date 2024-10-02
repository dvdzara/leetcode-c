FROM docker.io/library/ubuntu:24.04@sha256:b359f1067efa76f37863778f7b6d0e8d911e3ee8efa807ad01fbf5dc1ef9006b

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
