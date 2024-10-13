FROM docker.io/library/python:3.13.0-bookworm@sha256:a680a0edc77501edf235bcc10e81b23269b7320bbf6067b457534cf199007601

ENV CLANG_VERSION="18"

SHELL ["/bin/bash", "-o", "pipefail", "-c"]

# kics-scan ignore-block
# hadolint ignore=DL3008,DL3009
RUN echo "deb https://apt.llvm.org/bookworm llvm-toolchain-bookworm-$CLANG_VERSION main" | tee /etc/apt/sources.list.d/llvm.list && \
    curl "https://apt.llvm.org/llvm-snapshot.gpg.key" | tee /etc/apt/trusted.gpg.d/apt.llvm.org.asc && \
    apt-get update && \
    apt-get install -y --no-install-recommends "clang-$CLANG_VERSION" "clang-format-$CLANG_VERSION" "clang-tidy-$CLANG_VERSION" pkg-config ninja-build && \
    apt-get clean && \
    ln -s "/usr/bin/clang-tidy-$CLANG_VERSION" /usr/bin/clang-tidy

ENV CC="clang-$CLANG_VERSION"
ENV CXX="clang++-$CLANG_VERSION"

# renovate: datasource=pypi depName=meson versioning=pep440
ENV MESON_VERSION="1.5.2"
RUN pip install --root-user-action=ignore --no-cache-dir "meson==$MESON_VERSION"

ENTRYPOINT []
USER vscode
HEALTHCHECK NONE
