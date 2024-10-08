FROM mcr.microsoft.com/devcontainers/base:1.0.9-bookworm

ENV CLANG_VERSION="18"
# renovate: datasource=pypi depName=meson versioning=pep440
ENV MESON_VERSION="1.5.2"

SHELL ["/bin/bash", "-o", "pipefail", "-c"]

# hadolint ignore=DL3008,3009
RUN echo "deb http://apt.llvm.org/bookworm/ llvm-toolchain-bookworm-$CLANG_VERSION main" | tee /etc/apt/sources.list.d/llvm.list && \
    curl "https://apt.llvm.org/llvm-snapshot.gpg.key" | tee /etc/apt/trusted.gpg.d/apt.llvm.org.asc && \
    apt-get update && \
    apt-get install -y --no-install-recommends \
      "clang-$CLANG_VERSION" \
      "clang-format-$CLANG_VERSION" \
      "clang-tidy-$CLANG_VERSION" \
      pkg-config \
      python3 \
      python3-pip \
      ninja-build && \
    apt-get clean && \
    pip install --no-cache-dir --break-system-packages --compile "meson==$MESON_VERSION"

ENV CC="clang-$CLANG_VERSION"
ENV CXX="clang++-$CLANG_VERSION"

USER vscode
