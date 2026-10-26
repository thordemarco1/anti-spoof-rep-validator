# Verifier

Back to [README](../README.md) · Threat model: [THREAT_MODEL.md](../THREAT_MODEL.md)

> **Status: stub.** `verify.py` only parses arguments right now. Verification logic is TODO (phase 10 and 11).

## What it will do (planned)

Given a log of signed rep records from the device and the device's exported public key, the verifier will:

1. Check each record's ECDSA P-256 signature with the public key.
2. Check that the device serial matches the expected device.
3. Check that the monotonic counter strictly increases (rejects replay/duplicates/reordering).
4. Check that each record's `prev_hash` equals the hash of the previous record (detects deletion/insertion).
5. Print a clear accept/reject report and exit non-zero if anything fails.

## Setup

```bash
python -m venv .venv
source .venv/bin/activate      # Windows: .venv\Scripts\activate
pip install -r requirements.txt
python verify.py --help
```

## Usage (planned)

```bash
python verify.py --pubkey device_public.pem --log ../data/samples/session.log
```

TODO: add real example output (good log vs. tampered log) once implemented. Only the **public** key is ever needed here. Never put private keys in this repo (they are git-ignored, and on this device the private key cannot be read out anyway).

## Tests

TODO: add tests in [tests/](tests/) for: valid log, edited field, bad signature, replayed record, deleted record, reordered records, wrong device serial.
