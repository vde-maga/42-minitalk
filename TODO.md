## Minitalk Project Kanban Board

**Project Goal:** Implement a client/server communication program using UNIX signals (SIGUSR1 & SIGUSR2).

---

### To Do

*   **[ ] Setup Environment & Makefile**
    *   [x] Create project directory.
    *   [x] Initialize Git repository.
    *   [x] Create `Makefile` with required rules (`$(NAME)`, `all`, `clean`, `fclean`, `re`).
    *   [x] Ensure `Makefile` includes `-Wall`, `-Wextra`, and `-Werror` flags.
    *   [ ] (If using) Copy `libft` sources & Makefile into a dedicated folder (`libft/`).  Configure the main `Makefile` to compile `libft` first, then the project itself.
*   **[ ] Server Implementation - Mandatory Part**
    *   [x] Create server executable file named `server`.
    *   [x] Implement PID printing on server startup.
    *   [x] Implement signal handling for incoming data (SIGUSR1 & SIGUSR2).
    *   [x] Implement string reception logic using signals.
    *   [ ] Implement immediate string display upon reception.  (Performance check: 100 chars in <= 1 second)
    *   [ ] Ensure server can handle multiple client connections sequentially without restart.
    *   [ ] Handle potential errors gracefully (no segmentation faults, etc.).
    *   [ ] Free allocated memory to prevent leaks.
*   **[ ] Client Implementation - Mandatory Part**
    *   [ ] Create client executable file named `client`.
    *   [ ] Implement argument parsing for server PID and string to send.
    *   [ ] Implement signal sending logic (SIGUSR1 & SIGUSR2) to transmit the string character by character.
    *   [ ] Handle potential errors gracefully.
    *   [ ] Free allocated memory to prevent leaks.
*   **[ ] Testing - Mandatory Part**
    *   [ ] Create test cases for server functionality (multiple clients, long strings).
    *   [ ] Create test cases for client functionality (valid/invalid PID, empty string).
    *   [ ] Verify no memory leaks using appropriate tools.
    *   [ ] Ensure program adheres to the Norm.

---

### In Progress

*(Tasks moved here when actively being worked on)*

---

### Review

*   **[ ] Code Review - Mandatory Part** (Move from "In Progress" after completion)
    *   [ ] Peer review for code quality, adherence to the Norm, and error handling.
    *   [ ] Self-review of all implemented features.
*   **[ ] Performance Testing - Mandatory Part** (Move from "In Progress")
    *   [ ] Measure string display time with 100 characters.  Adjust as needed.

---

### Done

*   **[ ] Setup Environment & Makefile**
*   **[ ] Server Implementation - Mandatory Part**
*   **[ ] Client Implementation - Mandatory Part**
*   **[ ] Testing - Mandatory Part**

---

### Bonus Tasks (Only attempt if mandatory part is PERFECT)

*   **[ ] Server Acknowledgement Signal:** Implement server sending a signal back to the client upon message reception.
*   **[ ] Unicode Support:** Modify both client and server to handle Unicode characters correctly.  (Requires careful consideration of encoding/decoding).
*   **[ ] Bonus Makefile Rule:** Add bonus rule to `Makefile` for compilation.

