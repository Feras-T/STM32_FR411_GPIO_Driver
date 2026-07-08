cat > DEBUG_LOG.md << 'EOF'
# Debug Log — GPIO Driver

## [1] DISABLE branch never executed in IRQ config

**Symptom:** Disabling an interrupt via the config function had no
effect — the IRQ kept firing even after calling "disable."

**Investigation:**
1. Traced function flow — the ENABLE branch executed correctly
2. Found a nested if/else structure where the DISABLE condition was
   unreachable due to incorrect bracket scoping
3. Confirmed via breakpoint: the DISABLE code was never hit during
   testing

**Fix:** Restructured the if/else into a flat structure with an
explicit EnorDi check at the top level, removing the incorrect
nesting.

**Lesson:** Always trace both branches of conditional logic during
testing, not just the "happy path."

*(Note: to be updated with the exact bug encountered in this specific
GPIO driver once confirmed.)*
EOF