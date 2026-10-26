# ATECC608 Configuration Notes

Back to [README](../README.md) · See also [THREAT_MODEL.md](../THREAT_MODEL.md)

> ## ⚠️ WARNING: LOCKING IS PERMANENT AND IRREVERSIBLE
>
> Locking the ATECC608 **configuration zone** and **data zone** cannot be undone. Once locked, the slot configuration can never be changed, on this chip, ever. A wrong config can make the chip useless for this project.
>
> - Finish the slot plan below **on paper first** (phase 7).
> - Read the current config back and compare it with your plan **before** locking.
> - Check every value against the official Microchip ATECC608 datasheet and the SparkFun library documentation. Do not copy config bytes from random sources.
> - **Have a spare ATECC608 board** before running any lock step.
>
> No specific config byte values are given in this file on purpose. TODO: fill them in only after verifying them yourself.

## 1. Factory state (phase 6, read-only)

TODO: record serial number, revision, and whether config/data zones are already locked (read-only sketch: [06_atecc_info](../firmware/06_atecc_info/06_atecc_info.ino)).

## 2. Requirements for the slot plan

TODO: list what the project needs (e.g. one private signing key that is generated internally and never readable; a public key that can be exported; a monotonic counter).

## 3. Slot plan

| Slot | Purpose | Key type | Readable? | Writable? | Notes |
|------|---------|----------|-----------|-----------|-------|
| TODO | Signing private key | TODO | TODO | TODO | TODO |
| TODO | TODO | TODO | TODO | TODO | TODO |

## 4. Counter plan

TODO: which monotonic counter to use and how the firmware reads/increments it.

## 5. Config review checklist (before lock)

- [ ] Slot plan reviewed against datasheet
- [ ] Config read back and compared with plan
- [ ] Spare chip available
- [ ] Notebook entry written explaining the decision

## 6. Lock log (phase 8)

TODO: date, what was locked, exact sketch/version used, result. Write this in [lab-notebook.md](lab-notebook.md) too.

## 7. References

TODO: links to the datasheet sections and library docs you actually used.
