# FanQueue: Smart Ticket Prioritization System

**FanQueue** is a C++-based event management system with an innovative twist: it prioritizes ticket bookings from the waiting list based on a user's fan score for a particular artist. This ensures that the most loyal fans get access to limited seats first.

## 🎯 Project Goal

To implement a fair and intelligent ticket distribution system where loyal fans are rewarded with higher booking priority when events are overbooked or full.

## 🔧 Features

- 🎟️ **Intelligent Booking System**: Prioritizes waiting list based on fan engagement.
- 👤 **User Management**: Register and manage users.
- 🎤 **Artist-Based Fan Scoring**: Track user interactions with specific artists to compute a fan score.
- 📅 **Show Management**: Create, modify, and view event details.
- 💳 **Payment Integration**: Handle payment processes.
- 🔔 **Notification Module**: Notify users about their booking status or updates.
  
## 🧩 Modules

- `UserManagement.cpp`: Handles user registration and information.
- `ShowManagement.cpp`: Manages show creation and listings.
- `Bookings.cpp`: Processes bookings and prioritizes waiting list entries using fan score.
- `FanScore.cpp`: Maintains and calculates fan scores for each artist per user.
- `PaymentSubsystem.cpp`: Simulates or manages transactions.
- `Notifications.cpp`: Sends alerts and updates to users.

## 🚀 Getting Started

1. **Clone the repository**:
   ```bash
   git clone https://github.com/KaranShah1911/UserActivity.git
   cd UserActivity
