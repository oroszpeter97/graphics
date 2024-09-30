# Logger

## Enums
```
typedef enum {
	INFO,
	WARNING,
	ERROR,
	DEBUG
} LogLevel;
```

```
typedef enum {
	TO_CONSOLE,
	TO_FILE,
	TO_BOTH
} LogTarget;
```

## Usage

### Initialize
`log_init();`

### Logging
`log_message(<LogLevel>, <message>, <LogTarget>);`

## Example
`log_message(WARNING, "This is a warning", TO_CONSOLE);`