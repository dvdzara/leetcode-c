FROM registry.redhat.io/ubi9/ubi-minimal:9.4

RUN microdnf install -y --setopt install_weak_deps=0 \
  git \
  gpg \
  tar \
  findutils \
  clang \
  clang-tools-extra \
  meson \
  cmake \
  gettext \
  libffi-devel \
  && microdnf clean all

ENV CC=clang
ENV CXX=clang++

ENTRYPOINT [ "/bin/bash" ]
