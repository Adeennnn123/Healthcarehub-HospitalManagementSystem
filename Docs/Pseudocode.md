RegisterPatient() — Using Linked List
FUNCTION RegisterPatient()

INPUT name, age, disease, doctor

newNode -> CREATE PatientNode

newNode.name -> name
newNode.age -> age
newNode.disease -> disease
newNode.doctor -> doctor

newNode.next -> head
head -> newNode

DISPLAY "Patient Registered Successfully"

END FUNCTION

AddEmergencyPatient() — Using Priority Queue (Max-Heap)
FUNCTION AddEmergencyPatient()

INPUT name, severity

patient -> CREATE Node
patient.name -> name
patient.priority -> severity

InsertIntoMaxHeap(patient)

DISPLAY "Emergency Patient Added with Priority " + severity

END FUNCTION

ProcessNextEmergency() — Remove max from Priority Queue
FUNCTION ProcessNextEmergency()

IF heap IS EMPTY THEN
  DISPLAY "No Emergency Patients"
  RETURN
ENDIF

patient -> ExtractMax(heap)
DISPLAY "Processing Emergency Patient: " + patient.name

END FUNCTION

AddBillingEntry() — Using Stack
FUNCTION AddBillingEntry(amount)

Push(BillingStack, amount)
DISPLAY "Billing Entry Added: " + amount

END FUNCTION
UndoBilling() — Pop from Stack
FUNCTION UndoBilling()

IF BillingStack IS EMPTY THEN
  DISPLAY "Nothing to Undo"
  RETURN
ENDIF

billingEntry -> Pop(BillingStack)
DISPLAY "Undo Successful. Removed: " + billingEntry

END FUNCTION
