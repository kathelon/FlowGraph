# AGENTS.md

## Cursor Cloud specific instructions

### Codebase overview

This repository is **Flow Graph** — an Unreal Engine 5 plugin providing a design-agnostic node editor for scripting game event flow. It is a C++ plugin (`.uplugin`), **not** a standalone application.

There are two independently buildable components:

| Component | Type | Language | Build/Run |
|---|---|---|---|
| Flow plugin (Source/) | UE5 C++ plugin | C++ / C# (Build.cs) | Requires Unreal Engine 5 — cannot be compiled in this VM |
| Documentation site (docs/) | Jekyll static site | Ruby / Markdown | `cd docs && bundle exec jekyll serve --host 0.0.0.0 --port 4000` |

### Development tasks available in this environment

- **Jekyll docs site**: Build with `bundle exec jekyll build` or serve with `bundle exec jekyll serve` from the `docs/` directory. Runs on port 4000.
- **C++ static analysis**: Run `cppcheck --enable=warning,style --suppress=missingInclude --suppress=missingIncludeSystem --quiet Source/` from the repo root. Note: `unknownMacro` errors for UE macros like `TEXT`, `UPROPERTY` are expected — cppcheck doesn't have UE header context.
- **UE5 compilation**: Not possible in this VM (requires Unreal Engine installed). The plugin is compiled via Unreal Build Tool (UBT) as part of a UE project.

### Gotchas

- `bundle install` in `docs/` requires root permissions (use `sudo bundle install`) because gems install to `/var/lib/gems/`.
- The Jekyll site serves at `http://localhost:4000/` (not `/FlowGraph/` — the `baseurl` in `_config.yml` is only for GitHub Pages).
- The `wdm` gem in the Gemfile is Windows-only and is silently skipped on Linux — this is expected.
