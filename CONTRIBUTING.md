# Contributing

## Start here

- Read the [development guide](docs/development.md) and [research index](docs/research.md).
- Use a separate branch and a focused pull request.
- Record the original module hash, affected addresses and the reason for each change.

## Changes

- **Code:** keep patches small and verify actual written instructions with meaningful fixtures.
- **UI:** preserve native positions, touch targets, BMP dimensions, frame states and transparency rules.
- **Docs:** keep the main README as the installation/use guide. Add detailed research separately.
- **Evidence:** distinguish decompiler guesses, confirmed static behavior, fixture results and device tests.

## Releases

- Carry forward the entire previous payload and verify every path and hash.
- Put the complete `upgrade.lgu` in GitHub Releases; commit notes, recipes and evidence here.
- Include all earlier fixes. Never offer a separate patch package as a full release.
- Follow the [release checklist](docs/releases.md). Navigation redesign is outside the current UI scope.
