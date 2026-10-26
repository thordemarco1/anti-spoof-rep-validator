#!/usr/bin/env python3
"""
verify.py - Anti-Spoof Rep Validator log verifier (STUB).

Status: TODO. This file only defines the command-line interface. None of the
checks below are implemented yet, and running it on a log does NOT verify
anything.

Planned record format (TODO: finalize in phase 11 and keep in sync with
firmware/11_signed_reps/11_signed_reps.ino):

    One record per line. Proposed fields:
      version    int      record format version
      serial     hex      ATECC608 serial number (device ID)
      counter    int      monotonic counter, must strictly increase
      timestamp  int      device time in ms (informational only, not trusted)
      peak_deg   float    peak pitch angle of the rep
      prev_hash  hex(32)  SHA-256 of the previous record's signed bytes
                          (all zeros for the first record)
      signature  hex(64)  ECDSA P-256 signature, raw r||s (32 + 32 bytes)

    TODO: decide on the line encoding (CSV vs. JSON) and the exact byte
    serialization that gets hashed and signed. The verifier must rebuild the
    exact same bytes the device signed.

Planned checks per record:
    1. signature valid for SHA-256(signed bytes) under the device public key
    2. serial matches --expected-serial (if given)
    3. counter > previous counter (replay / reorder / duplicate detection)
    4. prev_hash == hash of previous record (deletion / insertion detection)
"""

import argparse
import sys


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(
        description=(
            "Verify signed rep records from the Anti-Spoof Rep Validator. "
            "STUB: verification is not implemented yet."
        )
    )
    parser.add_argument(
        "--pubkey",
        required=True,
        help="Path to the device's exported PUBLIC key (format TODO: PEM or raw hex).",
    )
    parser.add_argument(
        "--log",
        required=True,
        help="Path to the record log captured from the device's serial output.",
    )
    parser.add_argument(
        "--expected-serial",
        default=None,
        help="Optional ATECC608 serial number (hex) every record must match.",
    )
    parser.add_argument(
        "--verbose",
        "-v",
        action="store_true",
        help="Print the result of each check for each record.",
    )
    return parser


def load_public_key(path: str):
    """TODO: load an ECDSA P-256 public key with the `cryptography` package."""
    raise NotImplementedError("TODO: load_public_key")


def parse_records(path: str):
    """TODO: read the log file and yield parsed records (format above)."""
    raise NotImplementedError("TODO: parse_records")


def verify_records(records, public_key, expected_serial=None, verbose=False) -> bool:
    """TODO: run checks 1-4 on every record; return True only if all pass."""
    raise NotImplementedError("TODO: verify_records")


def main(argv=None) -> int:
    args = build_parser().parse_args(argv)
    print("verify.py is a stub: verification is not implemented yet (TODO).", file=sys.stderr)
    print(f"  pubkey: {args.pubkey}", file=sys.stderr)
    print(f"  log:    {args.log}", file=sys.stderr)
    # TODO: public_key = load_public_key(args.pubkey)
    # TODO: records = parse_records(args.log)
    # TODO: ok = verify_records(records, public_key, args.expected_serial, args.verbose)
    # TODO: return 0 if ok else 1
    return 2  # distinct exit code: "not implemented", never "verified"


if __name__ == "__main__":
    sys.exit(main())
