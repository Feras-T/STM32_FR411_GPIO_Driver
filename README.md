# STM32F411 GPIO Driver (Bare-Metal)

Register-level GPIO driver for STM32F411, written without HAL/LL libraries.

## Features
- Pin mode configuration (Input / Output / Alt Function / Analog select)
- Output type (Push-Pull / Open-Drain) and speed control
- Pull-up/Pull-down configuration
- Read/Write for single pins and full ports
- External interrupt (EXTI) support with NVIC priority configuration

## Architecture Decisions
- All register access done via direct pointer casting to peripheral
  base addresses (no vendor abstraction layer / no HAL)
- IRQ handling separated into three stages: interrupt config,
  priority config, and ISR handling — mirrors typical production
  driver structure

## Known Limitations
- Alternate Function (AFR) configuration not yet implemented
  (planned for peripheral drivers: SPI/UART/I2C pin muxing)
- Debounce handled in application layer, not driver layer

## Testing
- LED toggle on PA8 via interrupt trigger on PA9 (button)
- Verified interrupt priority nesting with two simultaneous EXTI lines
- Board: STM32F411RE Nucleo

## Bug Log
See [DEBUG_LOG.md](./DEBUG_LOG.md) for detailed debugging history.
EOF
