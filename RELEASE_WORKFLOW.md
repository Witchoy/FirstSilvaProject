# Release Branch Workflow (Unreal Engine Project)

This document describes the workflow for merging Assets into release.

## Branches

- `release` → Stable release branch  
- `Assets` → Branch containing Unreal Engine assets  
- `release-assets` → Temporary branch for merging assets into release  

## Workflow Goals

1. Create a dedicated branch `release-assets` from `release`  
2. Merge Unreal Engine assets into `release-assets`  
3. Merge `release-assets` back into `release`  

This approach avoids conflicts with binary Unreal assets (`.uasset`, `.umap`).

---

## Step 1 — Checkout the `release` branch

```bash
git checkout release
```

---

## Step 2 — Create the `release-assets` branch

```bash
git checkout -b release-assets
```

Now `release-assets` is based on the latest `release` branch.

---

## Step 3 — Merge the assets branch

Merge the Unreal Engine assets branch (`Assets`) into `release-assets`:

```bash
git merge Assets
```

If conflicts occur:

```bash
git add .
git commit
```

All assets are now contained in `release-assets`.

---

## Step 4 — Merge `release-assets` back into `release`

Once assets are validated and tested:

```bash
git checkout release
git merge release-assets
```