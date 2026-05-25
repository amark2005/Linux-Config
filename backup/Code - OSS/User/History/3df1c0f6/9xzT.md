# AvGeek API

A Minimal HTTP API server written in Go that **Returns** aircraft specifications.

## Overview

This api provides a single endpoint that returns a randomly selected aircraft from an internal dataset. It delivers a structured 

## Requirements

* Go

## Installation & Execution

1. Navigate to the project directory.
2. Run the server directly:
```bash
go run main.go

```


3. Alternatively, build and execute the binary:
```bash
go build -o avgeek-api
./avgeek-api

```



## Configuration

The server listens on port `6969` by default. You can override this by setting the `PORT` environment variable before starting the server:

```bash
PORT=8080 go run main.go

```

## API Reference

### Get Random Aircraft

Retrieves a single, randomly selected aircraft.

* **Method:** `GET`
* **Endpoint:** `/`

**Response Example:**

```json
{
  "name": "SR-71 Blackbird",
  "country": "USA",
  "speed": "Mach 3.3",
  "role": "Strategic Reconnaissance",
  "first_flight": 1964,
  "type": "Reconnaissance"
}

```

## Data Schema

The returned JSON object adheres to the following structure:

* `name` (string): The designation and name of the aircraft.
* `country` (string): The primary country or region of origin.
* `speed` (string): The maximum speed, typically denoted in Mach.
* `role` (string): The specific operational role of the aircraft.
* `first_flight` (integer): The year the aircraft took its maiden flight.
* `type` (string): The broad classification (e.g., Fighter, Bomber, Cargo, Passenger, Reconnaissance).