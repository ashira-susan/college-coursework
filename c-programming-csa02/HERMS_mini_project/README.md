# Hospital Emergency Resource Management System (HERMS)

CSA01 – Programming in C assignment.

## Development Environment
- OS: Ubuntu Linux (WSL)
- IDE: Visual Studio Code
- Compiler: GCC
- Build: Makefile

## Build & Run (in the Ubuntu/WSL terminal)

```bash
make
./herms
```

To rebuild from scratch:

```bash
make clean
make
```

## Project Structure

| File | Responsibility |
|---|---|
| `types.h` | `Resource` struct and shared constants |
| `resource.c/h` | Add, update, display resources |
| `search.c/h` | Linear search (ID/Name/Category/Department), binary search (ID) |
| `sort.c/h` | Recursive Quick Sort (by Quantity/Priority/Department/ID) |
| `merge.c/h` | Duplicate detection and department merging |
| `analysis.c/h` | Availability analysis, critical/low-stock display |
| `fileio.c/h` | Save/load (`resources.dat`, binary) and report generation (`consolidated_report.txt`) |
| `menu.c/h` | Menu-driven interface |
| `main.c` | Program entry point |

## Design Decisions

- **Data storage:** array of `Resource` structs (`MAX_RECORDS = 100`), no dynamic memory — not required by the assignment.
- **Status field** (`CRITICAL` / `LOW` / `ADEQUATE`) is always derived from quantity vs. threshold, recalculated on every add, update, and merge — never entered directly.
- **Search:** linear search works on any field regardless of array order; binary search is restricted to Resource ID, and the array is automatically sorted by ID first so it never runs on unsorted data.
- **Sort:** recursive Quick Sort is the single recursion requirement for this project — implemented once, applied to four sort criteria via a comparator.
- **Duplicate identity:** same ID, OR same Name + Category. Department is deliberately excluded from the identity, since consolidating records *across* departments is the entire point of merging.
- **Merge:** duplicate quantities are summed into one record; the department field absorbs all contributing departments (e.g. `"ICU, Emergency"`), checked with `strstr()` so a department is never listed twice.
- **File storage:** `resources.dat` uses binary `fwrite`/`fread` for efficient, exact struct persistence; `consolidated_report.txt` is a separate human-readable report.
- **Pointers:** used for in-place record updates (`Resource *`), record-count management (`int *count`), and swapping during Quick Sort — each with a genuine purpose rather than being decorative.
- **Deliberately excluded:** linked lists, dynamic memory, databases, networking, threads, GUI — none are required by the assignment.

## Sample Usage

1. Choose `1` to add a resource, entering ID, name, category, department, quantity, threshold, priority.
2. Add records for the same resource under different departments (e.g. Oxygen Cylinder under ICU and under Emergency).
3. Choose `6` to see duplicates identified.
4. Choose `7` to merge them into one consolidated record.
5. Choose `8`/`9` to see the availability analysis and critical/low-stock lists.
6. Choose `10` to write the consolidated report to `consolidated_report.txt`.
7. Choose `11` to save all records to `resources.dat` before exiting (choose `12` or answer `y` at startup to reload them next time).
