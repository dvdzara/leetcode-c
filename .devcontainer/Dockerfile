# kics-scan disable=df746b39-6564-4fed-bf85-e9c44382303c,965a08d7-ef86-4f14-8792-4a3b2098937e

FROM docker.io/library/python:3.13.0-bookworm@sha256:feee4734fdc44cc09a3c9cdb72e05bb8ff7e964f64766bc1a68638b2c667cf35

# Configure shell.
SHELL ["/bin/bash", "-o", "pipefail", "-c"]

# Configure apt.
ARG DEBIAN_FRONTEND="noninteractive"
RUN rm \
        /etc/apt/apt.conf.d/70debconf \
        /etc/apt/apt.conf.d/docker-autoremove-suggests \
        /etc/apt/apt.conf.d/docker-clean \
        /etc/apt/apt.conf.d/docker-gzip-indexes && \
    echo -e 'APT::Get::Install-Recommends "false";\nAPT::Get::Install-Suggests "false";' | tee /etc/apt/apt.conf.d/01-ci-no-extra-pkgs

# Install clang and dependencies of meson and valgrind.

# hadolint ignore=DL3008,DL3009
RUN echo "deb https://apt.llvm.org/bookworm llvm-toolchain-bookworm-18 main" | tee /etc/apt/sources.list.d/llvm.list && \
    curl "https://apt.llvm.org/llvm-snapshot.gpg.key" | tee /etc/apt/trusted.gpg.d/apt.llvm.org.asc && \
    apt-get update && \
    apt-get install -y --no-install-recommends \
        clang-18 \
        clang-format-18 \
        clang-tidy-18 \
        # Used by valgrind.
        libc6-dbg \
        # Used by meson.
        ninja-build \
        # Used by meson-lsp.
        pkg-config && \
    # fix: clang-tidy wasn't found by meson.
    ln -s /usr/bin/clang-tidy-18 /usr/bin/clang-tidy

ENV CC="clang-18"
ENV CXX="clang++-18"

# Install meson.

# renovate: datasource=pypi depName=meson versioning=pep440
ENV MESON_VERSION="1.5.2"
RUN pip install --root-user-action=ignore --no-cache-dir --progress-bar=off "meson==$MESON_VERSION"

# Install valgrind.

ENV VALGRIND_VERSION="3.23.0"

WORKDIR /tmp/valgrind
RUN curl -sO "https://sourceware.org/pub/valgrind/valgrind-$VALGRIND_VERSION.tar.bz2" && \
    bzip2 --decompress "valgrind-$VALGRIND_VERSION.tar.bz2" && \
    tar -xf "valgrind-$VALGRIND_VERSION.tar"

WORKDIR /tmp/valgrind/valgrind-$VALGRIND_VERSION
RUN ./configure && \
    make -j "$(nproc)" && \
    make install

ENTRYPOINT []
USER vscode
HEALTHCHECK NONE
